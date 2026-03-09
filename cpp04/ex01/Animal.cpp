#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return m_type;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	m_type = src.getType();
}
Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &src)
	{
		m_type = src.getType();
	}
	return *this;
}


void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
