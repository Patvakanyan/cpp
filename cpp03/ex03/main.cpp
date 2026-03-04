#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== ex03 tests =====" << std::endl;

	std::cout << "\n[1] ClapTrap basic behavior" << std::endl;
	ClapTrap clap("CL4P");
	clap.attack("dummy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << "\n[2] ScavTrap specific behavior" << std::endl;
	ScavTrap scav("SC4V");
	scav.attack("intruder");
	scav.guardGate();
	scav.takeDamage(60);
	scav.beRepaired(25);

	std::cout << "\n[3] FragTrap specific behavior" << std::endl;
	FragTrap frag("FR4G");
	frag.attack("boss");
	frag.highFivesGuys();
	frag.takeDamage(40);
	frag.beRepaired(20);

	std::cout << "\n[4] DiamondTrap combined behavior" << std::endl;
	DiamondTrap diamond("D14M");
	diamond.attack("raid-boss");
	diamond.whoAmI();
	diamond.takeDamage(35);
	diamond.beRepaired(15);

	DiamondTrap diamondCopy(diamond);
	diamondCopy.whoAmI();

	std::cout << "\n[5] Copy assignment checks" << std::endl;
	ClapTrap clapAssigned;
	clapAssigned = clap;
	clapAssigned.attack("copied-target");

	ScavTrap scavAssigned;
	scavAssigned = scav;
	scavAssigned.attack("copied-intruder");

	FragTrap fragAssigned;
	fragAssigned = frag;
	fragAssigned.highFivesGuys();

	DiamondTrap diamondAssigned;
	diamondAssigned = diamond;
	diamondAssigned.whoAmI();
	diamondAssigned.attack("copied-raid-boss");

	std::cout << "\n[6] Dead-state checks" << std::endl;
	frag.takeDamage(200);
	frag.attack("after-death");
	frag.beRepaired(10);

	clap.takeDamage(1000);
	clap.attack("after-death");
	clap.beRepaired(5);

	std::cout << "\n===== End of tests =====" << std::endl;
	return 0;
}
