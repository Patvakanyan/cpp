#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		PresidentialPardonForm form("Alice");
		ShrubberyCreationForm shrubbery("Garden");
		RobotomyRequestForm robotomy("Target");
		std::cout << form << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;

		shrubbery.beSigned(bob);
		shrubbery.execute(bob);
		robotomy.beSigned(bob);
		robotomy.execute(bob);
		bob.signForm(form);
		bob.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
