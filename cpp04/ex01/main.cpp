#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const int size = 4;
	Animal *animals[size];

	for (int i = 0; i < size; ++i)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < size; ++i)
		delete animals[i];

	Dog d1;
	Dog d2(d1);
	Cat c1;
	Cat c2;
	c2 = c1;
	return 0;
}
