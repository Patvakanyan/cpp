#include "Zombie.hpp"

int	main(void)
{
	std::cout << "=== Heap Zombie ===" << std::endl;
	Zombie	*heapZombie;
	heapZombie = newZombie("HeapZomb");
	heapZombie->announce();
	delete	heapZombie;
	std::cout << "=== Stack Zombie ===" << std::endl;
	randomChump("StackZomb");
}
