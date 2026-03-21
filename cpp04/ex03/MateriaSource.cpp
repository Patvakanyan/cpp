#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		m_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		m_slots[i] = other.m_slots[i] ? other.m_slots[i]->clone() : NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_slots[i])
				delete m_slots[i];
			m_slots[i] = other.m_slots[i] ? other.m_slots[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_slots[i];
		m_slots[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *src)
{
	if (!src)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (m_slots[i] == NULL)
		{
			m_slots[i] = src;
			return;
		}
	}
	delete src;
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_slots[i] && type == m_slots[i]->getType())
			return m_slots[i]->clone();
	}
	return NULL;
}
