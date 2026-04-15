#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "Alice");
		AForm *shrubbery = intern.makeForm("shrubbery creation", "Garden");
		AForm *robotomy = intern.makeForm("robotomy request", "Target");
		std::cout << *form << std::endl;
		std::cout << *shrubbery << std::endl;
		std::cout << *robotomy << std::endl;

		shrubbery->beSigned(bob);
		shrubbery->execute(bob);
		robotomy->beSigned(bob);
		robotomy->execute(bob);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		delete shrubbery;
		delete robotomy;
	}
	catch (const std::exception &e)
	{

		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
