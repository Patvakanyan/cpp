#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Create Bureaucrats ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 100);
		std::cout << boss << std::endl;
		std::cout << worker << std::endl;
		std::cout << "\n=== Create Forms ===" << std::endl;
		Form easy("Easy Form", 120, 100);
		Form hard("Hard Form", 10, 5);
		std::cout << easy << std::endl;
		std::cout << hard << std::endl;
		std::cout << "\n=== Signing Tests ===" << std::endl;
		worker.signForm(easy);
		worker.signForm(hard);
		boss.signForm(hard);
		std::cout << "\n=== Final Form States ===" << std::endl;
		std::cout << easy << std::endl;
		std::cout << hard << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Invalid Form Test ===" << std::endl;
	try
	{
		Form invalid("Invalid Form", 0, 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception while creating form: " << e.what() << std::endl;
	}

	return 0;
}
