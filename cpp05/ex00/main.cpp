#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Valid Bureaucrat Test ===" << std::endl;
	try
	{
		Bureaucrat b("Alice", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Too High Constructor Test ===" << std::endl;
	try
	{
		Bureaucrat bad("TooHigh", 0);
		std::cout << bad << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Too Low Constructor Test ===" << std::endl;
	try
	{
		Bureaucrat bad("TooLow", 151);
		std::cout << bad << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Increment Overflow Test ===" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		top.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Decrement Overflow Test ===" << std::endl;
	try
	{
		Bureaucrat low("Low", 150);
		low.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
