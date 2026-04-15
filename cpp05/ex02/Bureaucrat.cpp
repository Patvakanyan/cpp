#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name), m_grade(other.m_grade)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	m_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	m_grade = other.getGrade();
	return *this;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

const std::string &Bureaucrat::getName() const
{
	return m_name;
}
void Bureaucrat::incrementGrade()
{
	if (m_grade == 1)
		throw GradeTooHighException();
	m_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (m_grade == 150)
		throw GradeTooLowException();
	m_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute "
				  << form.getName() << " because "
				  << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign "
				  << f.getName() << " because "
				  << e.what() << std::endl;
	}
}
