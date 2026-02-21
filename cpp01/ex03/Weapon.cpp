#include "Weapon.hpp"

Weapon::Weapon(const std::string &typeSet): type(typeSet){}
Weapon::~Weapon(){}
void Weapon::setType(const std::string &typeSet)
{
	type = typeSet;
}

const std::string &Weapon::getType() const
{
	return type;
}
