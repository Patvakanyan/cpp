#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Constructors =====" << std::endl;
	ClapTrap defCtor;
	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");
	ClapTrap copyCtor(alpha);
	ClapTrap assigned;
	assigned = beta;

	std::cout << "\n===== Basic Actions =====" << std::endl;
	alpha.attack("Bandit");
	alpha.takeDamage(3);
	alpha.beRepaired(2);

	std::cout << "\n===== Energy Depletion =====" << std::endl;
	for (int i = 0; i < 11; ++i)
		beta.attack("Target");

	std::cout << "\n===== HP Edge Cases =====" << std::endl;
	copyCtor.takeDamage(15);
	copyCtor.attack("Nobody");
	copyCtor.beRepaired(5);

	std::cout << "\n===== End of tests =====" << std::endl;
	return 0;
}
