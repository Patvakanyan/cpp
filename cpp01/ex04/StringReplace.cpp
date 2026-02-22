#include "StringReplace.hpp"

bool stringReplace(const std::string &filename, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return false;

	std::ifstream in(filename.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error: could not open file\n";
		return false;
	}

	std::ofstream out((filename + ".replace").c_str());
	if (!out.is_open())
	{
		std::cerr << "Error: could not create file\n";
		return false;
	}

	std::string line;
	while (std::getline(in, line))
	{
		size_t pos = 0;
		while((pos = line.find(s1, pos)) != std::string::npos )
			line = line.substr(0, pos) + s2 + line.substr(pos+s1.length());
		out << line << "\n";
	}
	return true;
}
