#include "Character.hpp"

Character::Character() : m_name("default")
{
	for (int i = 0; i < 4; i++)
		m_slots[i] = NULL;
	m_inventory = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_slots[i];
		m_slots[i] = NULL;
	}
	clearInventory();
}

Character::Character(const std::string &name) : m_name(name)
{
	for (int i = 0; i < 4; i++)
		m_slots[i] = NULL;
	m_inventory = NULL;
}

Character::Character(const Character &other) : m_name(other.m_name), m_inventory(NULL)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.m_slots[i])
			m_slots[i] = other.m_slots[i]->clone();
		else
			m_slots[i] = NULL;
	}
	copyInventory(other);
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		for (int i = 0; i < 4; i++)
		{
			if (m_slots[i])
				delete m_slots[i];
			m_slots[i] = other.m_slots[i] ? other.m_slots[i]->clone() : NULL;
		}
		clearInventory();
		copyInventory(other);
	}
	return *this;
}

std::string const &Character::getName() const
{
	return m_name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	AMateria *newMateria = m ? m->clone() : NULL;
	delete m;
	for (int i = 0; i < 4; i++)
	{
		if (!m_slots[i])
		{
			m_slots[i] = newMateria;
			return;
		}
	}
	delete newMateria;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !m_slots[idx])
		return;
	CharacterInventory *newNode = new CharacterInventory;
	newNode->slot = m_slots[idx];
	newNode->next = NULL;
	if (!m_inventory)
		m_inventory = newNode;
	else
	{
		CharacterInventory *tail = m_inventory;
		while (tail->next)
			tail = tail->next;
		tail->next = newNode;
	}
	m_slots[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (m_slots[idx])
		m_slots[idx]->use(target);
}

void Character::copyInventory(const Character &other)
{
	m_inventory = NULL;
	CharacterInventory *tail = NULL;
	for (CharacterInventory *current = other.m_inventory; current; current = current->next)
	{
		CharacterInventory *newNode = new CharacterInventory;
		newNode->slot = current->slot ? current->slot->clone() : NULL;
		newNode->next = NULL;
		if (!m_inventory)
			m_inventory = newNode;
		else
			tail->next = newNode;
		tail = newNode;
	}
}

void Character::clearInventory()
{

	CharacterInventory *current = m_inventory;
	while (current)
	{
		CharacterInventory *next = current->next;
		delete current->slot;
		delete current;
		current = NULL;
		current = next;
	}
	m_inventory = NULL;
}
