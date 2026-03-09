#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->m_type = src.m_type;
	}
	return *this;
}

std::string AAnimal::getType() const
{
	return this->m_type;
}

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->m_type = "AAnimal";
}
