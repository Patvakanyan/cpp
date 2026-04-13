#include "Form.hpp"

Form::Form() : m_name("Default"), m_gradeToSign(150), m_gradeToExecute(150), m_signed(false)
{
}

Form::~Form()
{
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: m_name(name),
	  m_gradeToSign(gradeToSign),
	  m_gradeToExecute(gradeToExecute),
	  m_signed(false)
{
	if (m_gradeToSign < 1 || m_gradeToExecute < 1)
		throw GradeTooHighException();
	if (m_gradeToSign > 150 || m_gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : m_name(other.m_name), m_gradeToSign(other.m_gradeToSign),
								m_gradeToExecute(other.m_gradeToExecute), m_signed(other.m_signed)
{
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	m_signed = other.m_signed;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade number is too small";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade number is too large";
}

void Form::beSigned(const Bureaucrat &person)
{
	if (m_signed)
		return;
	if (person.getGrade() > m_gradeToSign)
		throw GradeTooLowException();
	m_signed = true;
}

int Form::getGradeToExecute() const
{
	return m_gradeToExecute;
}

int Form::getGradeToSign() const
{
	return m_gradeToSign;
}

bool Form::getSigned() const
{
	return m_signed;
}

std::string Form::getName() const
{
	return m_name;
}

std::ostream &operator<<(std::ostream &os, const Form &b)
{
	os << b.getName() << ", form grade to sign " << b.getGradeToSign()
	   << ", form grade to execute " << b.getGradeToExecute()
	   << ", is signed " << (b.getSigned() ? "yes" : "no");
	return os;
}
