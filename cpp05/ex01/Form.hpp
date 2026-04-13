#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string m_name;
	const int m_gradeToSign;
	const int m_gradeToExecute;
	bool m_signed;

public:
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

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

	void beSigned(const Bureaucrat &person);
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;
	std::string getName() const;
};
std::ostream &operator<<(std::ostream &os, const Form &b);
#endif
