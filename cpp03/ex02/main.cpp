#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== FragTrap tests =====" << std::endl;
	FragTrap frag("FR4G");
	frag.attack("boss");
	frag.highFivesGuys();
	frag.takeDamage(40);
	frag.beRepaired(20);

	std::cout << "\n===== FragTrap copy tests =====" << std::endl;
	FragTrap fragCopy(frag);
	FragTrap fragAssigned;
	fragAssigned = frag;
	fragCopy.attack("copy-boss");
	fragAssigned.highFivesGuys();

	std::cout << "\n===== FragTrap dead-state tests =====" << std::endl;
	frag.takeDamage(200);
	frag.attack("after-death");
	frag.beRepaired(10);

	std::cout << "\n===== End of FragTrap tests =====" << std::endl;
	return 0;
}
