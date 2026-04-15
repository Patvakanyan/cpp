#include "AForm.hpp"

AForm::AForm() : m_name("Default"), m_gradeToSign(150), m_gradeToExecute(150), m_signed(false)
{
}

AForm::~AForm()
{
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
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

AForm::AForm(const AForm &other) : m_name(other.m_name), m_gradeToSign(other.m_gradeToSign),
								   m_gradeToExecute(other.m_gradeToExecute), m_signed(other.m_signed)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	m_signed = other.m_signed;
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "The grade number is too small";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "The grade number is too large";
}

void AForm::beSigned(const Bureaucrat &person)
{
	if (m_signed)
		return;
	if (person.getGrade() > m_gradeToSign)
		throw GradeTooLowException();
	m_signed = true;
}

int AForm::getGradeToExecute() const
{
	return m_gradeToExecute;
}

int AForm::getGradeToSign() const
{
	return m_gradeToSign;
}

bool AForm::getSigned() const
{
	return m_signed;
}

std::string AForm::getName() const
{
	return m_name;
}

void AForm::checkRequirements(Bureaucrat const &executor) const
{
	if (!m_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > m_gradeToExecute)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &b)
{
	os << b.getName() << ", form grade to sign " << b.getGradeToSign()
	   << ", form grade to execute " << b.getGradeToExecute()
	   << ", is signed " << (b.getSigned() ? "yes" : "no");
	return os;
}
