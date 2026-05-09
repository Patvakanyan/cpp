#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

int main()
{
	try
	{
		BitcoinExchange btc;
		btc.parseData("data.csv");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
