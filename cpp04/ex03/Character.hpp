#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

struct CharacterInventory
{
	AMateria *slot;
	CharacterInventory *next;
};

class Character : public ICharacter
{
public:
	Character();
	Character(const std::string &name);
	Character &operator=(const Character &other);
	Character(const Character &other);
	~Character();

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	void copyInventory(const Character &other);
	void clearInventory();
private:
	AMateria *m_slots[4];
	std::string m_name;
	CharacterInventory *m_inventory;
};

#endif
