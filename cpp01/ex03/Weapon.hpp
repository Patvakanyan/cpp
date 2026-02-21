#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	public:
		Weapon(const std::string &typeSet);
		~Weapon();
		const std::string &getType() const;
		void setType(const std::string &type);
	private:
		std::string type;
};

#endif
