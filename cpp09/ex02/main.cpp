#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pmergeMe;
		pmergeMe.checkInput(argc, argv);
		std::cout << "Before: ";
		pmergeMe.printVector();
		pmergeMe.sort();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
