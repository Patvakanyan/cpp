#include "HumanB.hpp"

HumanB::HumanB(const std::string name): Name(name), gun(NULL)
{
}
HumanB::~HumanB(){}
void HumanB::setWeapon(Weapon &tmp)
{
	gun = &tmp;
}

void HumanB::attack()
{
	if(!gun)
		return ;
	std::cout << Name << " attacks with their " << gun->getType() << std::endl;
}
