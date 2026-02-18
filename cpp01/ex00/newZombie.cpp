#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*ptrZomb;

	ptrZomb = new Zombie(name);
	return (ptrZomb);
}
