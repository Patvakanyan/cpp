#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== TEST 1: Constructors =====" << std::endl;
	ScavTrap defaultTrap;
	ScavTrap alpha("Alpha");
	ScavTrap bravo("Bravo");

	std::cout << "\n===== TEST 2: Copy Constructor / Assignment =====" << std::endl;
	ScavTrap copyAlpha(alpha);
	ScavTrap assignedTrap;
	assignedTrap = bravo;

	std::cout << "\n===== TEST 3: Attack + Damage + Repair =====" << std::endl;
	alpha.attack("Bandit");
	alpha.takeDamage(35);
	alpha.beRepaired(20);

	std::cout << "\n===== TEST 4: guardGate() =====" << std::endl;
	alpha.guardGate();

	std::cout << "\n===== TEST 5: Energy Depletion (50 attacks) =====" << std::endl;
	for (int i = 0; i < 50; ++i)
		bravo.attack("Training Dummy");
	std::cout << "One more attack after energy is empty:" << std::endl;
	bravo.attack("Training Dummy");

	std::cout << "\n===== TEST 6: Dead Trap Cannot Act =====" << std::endl;
	copyAlpha.takeDamage(100);
	copyAlpha.attack("Nobody");
	copyAlpha.beRepaired(10);

	std::cout << "\n===== End of manual tests =====" << std::endl;
	return 0;
}
