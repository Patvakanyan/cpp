#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &src);
	std::string getType() const;
	virtual void makeSound() const = 0;

protected:
	std::string m_type;
};

#endif
