#include "AMateria.hpp"


AMateria::AMateria(std::string const &type) : m_type(type)
{
}

std::string const &AMateria::getType() const
{
	return m_type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}

AMateria::AMateria(): m_type("default")
{
}

AMateria::~AMateria()
{
}
AMateria::AMateria(const AMateria &other) : m_type(other.m_type)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		m_type = other.m_type;
	return *this;
}
