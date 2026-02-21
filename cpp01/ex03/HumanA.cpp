#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &tmp):Name(name), gun(tmp)
{}
HumanA::~HumanA(){}
void HumanA::attack()
{
	std::cout << Name << " attacks with their " << gun.getType() << std::endl;
}
