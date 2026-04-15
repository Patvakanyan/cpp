#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137),
												 m_target("default")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137),
																		  m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
																				   m_target(other.m_target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::checkRequirements(executor);
	std::string file = m_target + "_shrubbery";
	std::ofstream my_file(file.c_str());

	if (my_file.is_open())
	{
		my_file << ",@@@@@@@,\n"
				<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
				<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
				<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
				<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
				<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
				<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
				<< "       |o|        | |         | |\n"
				<< "       |.|        | |         | |\n"
				<< "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
		my_file.close();
	}
}
