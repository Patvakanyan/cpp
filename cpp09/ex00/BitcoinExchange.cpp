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
		return std::make_pair("", "");

	std::string first = title.substr(start, (pos > start ? pos - start : 0));

	size_t second_start = pos + c.length();
	std::string second = "";
	if (second_start < end)
		second = title.substr(second_start, end - second_start);
	return std::make_pair(first, second);
}

bool BitcoinExchange::checkArgs(const std::string &title, std::string c) const
{
	std::pair<std::string, std::string> title_items = trem(title, c);
	if (title_items.first == "date" && (title_items.second == "exchange_rate" || title_items.second == "value"))
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
void BitcoinExchange::parseInputFile(const std::string &file)
{
	std::ifstream myFile(file.c_str());
	std::string line;
	char *end;
	if (!myFile.is_open())
		throw std::runtime_error("Error: Could not open file " + file);
	if (!std::getline(myFile, line))
		throw std::runtime_error("Error: empty file");
	if (!checkArgs(line, " | "))
		throw std::runtime_error("Error: database header must be 'date,'");
	while (std::getline(myFile, line))
	{
		std::pair<std::string, std::string> tmp = trem(line, " | ");
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

