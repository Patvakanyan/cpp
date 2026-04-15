#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string m_name;
	const int m_gradeToSign;
	const int m_gradeToExecute;
	bool m_signed;

public:
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	virtual void execute(Bureaucrat const &executor) const = 0;
	void beSigned(const Bureaucrat &person);
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;
	void checkRequirements(Bureaucrat const &executor) const;
	std::string
	getName() const;
};
std::ostream &operator<<(std::ostream &os, const AForm &b);
#endif
