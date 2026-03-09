#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *a = new Animal();
	const Animal *d = new Dog();
	const Animal *c = new Cat();

	a->makeSound();
	d->makeSound();
	c->makeSound();

	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();
	wa->makeSound();
	wc->makeSound();

	delete a;
	delete d;
	delete c;
	delete wa;
	delete wc;
	return 0;
}
