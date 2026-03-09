#include "Cat.hpp"

Cat::Cat() : Animal(), m_brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete m_brain;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	m_brain = new Brain(*src.m_brain);
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete m_brain;
		m_brain = new Brain(*src.m_brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
