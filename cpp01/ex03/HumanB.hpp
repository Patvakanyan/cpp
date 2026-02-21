#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(const std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &tmp);
	private:
		std::string Name;
		Weapon *gun;
};
#endif
