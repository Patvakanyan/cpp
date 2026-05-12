#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : exchangeRates(other.exchangeRates)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->exchangeRates = other.exchangeRates;
	return *this;
}

static std::pair<std::string, std::string> trem(const std::string &title, std::string c)
{
	size_t start = 0;
	size_t end = title.size();

	while (start < end && std::isspace(static_cast<unsigned char>(title[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(title[end - 1])))
		end--;

	size_t pos = title.find(c);
	if (pos == std::string::npos)
		return std::make_pair(title, "");

	std::string first = title.substr(start, (pos > start ? pos - start : 0));

	size_t second_start = pos + c.length();
	std::string second = "";
	if (second_start < end)
		second = title.substr(second_start, end - second_start);
	return std::make_pair(first, second);
}

bool BitcoinExchange::checkArgs(const std::string &title, std::string c, std::string args) const
{
	std::pair<std::string, std::string> title_items = trem(title, c);
	std::pair<std::string, std::string> args_items = trem(args, c);
	if (title_items.first == args_items.first && (title_items.second == args_items.second || title_items.second == "value"))
		return true;
	return false;
}

bool BitcoinExchange::isLeapYear(int year) const
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return (year % 4 == 0);
}

int BitcoinExchange::daysInMonth(int year, int month) const
{
	static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		return 29;
	return days[month - 1];
}
bool BitcoinExchange::parseDate(const std::string &date) const
{
	if (date.length() < 10)
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int maxDays = daysInMonth(year, month);
	if (day < 1 || day > maxDays)
		return false;
	return true;
}
void BitcoinExchange::parseData(const std::string &file)
{
	std::ifstream myFile(file.c_str());
	std::string line;
	char *end;
	if (!myFile.is_open())
		throw std::runtime_error("Error: Could not open file " + file);
	if (!std::getline(myFile, line))
		throw std::runtime_error("Error: empty file");
	if (!checkArgs(line, ",", "date,exchange_rate"))
		throw std::runtime_error("Error: database header must be 'date,'");
	while (std::getline(myFile, line))
	{
		std::pair<std::string, std::string> tmp = trem(line, ",");
		if (!this->parseDate(tmp.first))
			throw std::runtime_error("Error: incorrect date");
		double rate = std::strtod(tmp.second.c_str(), &end);
		if (tmp.second.c_str() == end)
			throw std::runtime_error("Error: invalid exchange rate");
		if (errno == ERANGE)
			throw std::runtime_error("Error: exchange rate out of range");
		if (rate < 0)
			throw std::runtime_error("Error: negative exchange rate");
		this->exchangeRates[tmp.first] = rate;
	}
}
void BitcoinExchange::parseInputFile(const std::string &input)
{
	std::ifstream myFile(input.c_str());
	std::string line;
	if (!myFile.is_open())
		throw std::runtime_error("Error: Could not open file " + input);
	if (!std::getline(myFile, line))
		throw std::runtime_error("Error: empty file");
	if (!checkArgs(line, " | ", "date | value"))
		throw std::runtime_error("Error: database header must be 'date,'");
	while (std::getline(myFile, line))
	{
		if (line.empty())
			continue;
		std::pair<std::string, std::string> tmp = trem(line, " | ");
		if (!this->parseDate(tmp.first))
		{
			std::cerr << "Error: bad input => " << tmp.first << std::endl;
			continue;
		}
		char *end;
		double value = std::strtod(tmp.second.c_str(), &end);
		if (tmp.second.c_str() == end)
		{
			std::cerr << "Error: invalid value" << std::endl;
			continue;
		}
		if (errno == ERANGE)
		{
			std::cerr << "Error: value out of range" << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: negative value" << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: value too large" << std::endl;
			continue;
		}
		std::map<std::string, double>::const_iterator it = this->exchangeRates.lower_bound(tmp.first);
		if (it == this->exchangeRates.end())
			it--;
		std::cout << tmp.first << " => " << value << " = " << value * it->second << std::endl;
	}
}
