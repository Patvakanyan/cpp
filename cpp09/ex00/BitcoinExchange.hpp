#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double> exchangeRates;
	bool checkArgs(const std::string &title, std::string c, std::string args) const;
	bool isLeapYear(int year) const;
	int daysInMonth(int year, int month) const;
	bool parseDate(const std::string &date) const;
	bool parseInputFile(const std::string &input) const;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void parseInputFile(const std::string &file);
	void parseData(const std::string &file);
};

#endif
