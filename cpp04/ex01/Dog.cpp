#include "Dog.hpp"

Dog::Dog() : Animal(), m_brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	m_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete m_brain	;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	m_brain = new Brain(*src.m_brain);
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete m_brain;
		m_brain = new Brain(*src.m_brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
