#include "Intern.hpp"

Intern::Intern()
{
}
Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm *result = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			result = forms[i];
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] != result)
			delete forms[i];
	}
	if (result == NULL)
	{
		std::cout << "Intern cannot create form: " << formName << std::endl;
	}
	return result;
}
