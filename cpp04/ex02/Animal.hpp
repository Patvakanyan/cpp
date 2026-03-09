#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	std::string getType() const;
	virtual void makeSound() const;

protected:
	std::string m_type;
};

#endif
