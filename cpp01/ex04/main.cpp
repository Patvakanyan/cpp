#include <iostream>
#include <fstream>
#include <string>
#include "StringReplace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty() || s1 == s2)
	{
		std::cerr << "Error: s1 and s2 must be non-empty and different" << std::endl;
		return 1;
	}
	if (fileName.empty())
	{
		std::cerr << "Error: filename must be non-empty\n";
		return 1;
	}
	if(!stringReplace(fileName, s1, s2))
	{
		std::cerr << "Error: string replacement failed\n";
		return 1;
	}
	return 0;
}
