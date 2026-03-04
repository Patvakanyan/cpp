#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), m_name("default")
{
	std::cout << "DiamondTrap default constructor call" << std::endl;
	m_hitPoints = FragTrap::m_hitPoints;
	m_energyPoints = ScavTrap::m_energyPoints;
	m_attackDamage = FragTrap::m_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor call" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
											 FragTrap(name), ScavTrap(name), m_name(name)
{
	std::cout << "Constructor with name called for DiamondTrap " << m_name << std::endl;
	m_hitPoints = FragTrap::m_hitPoints;
	m_energyPoints = ScavTrap::m_energyPoints;
	m_attackDamage = FragTrap::m_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src), m_name(src.m_name)
{
	std::cout << "Copy constructor called for DiamondTrap " << src.m_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "Copy assignment operator called for DiamondTrap " << src.m_name << std::endl;
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	m_name = src.m_name;
	return *this;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (m_hitPoints <= 0 || m_energyPoints <= 0)
	{
		std::cout << "DiamondTrap " << m_name << " cannot repair.\n";
		return;
	}
	m_hitPoints += amount;
	m_energyPoints--;
	std::cout << "DiamondTrap " << m_name << " repairs itself for "
			  << amount << " hit points!\n";
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (amount >= m_hitPoints)
		m_hitPoints = 0;
	else
		m_hitPoints -= amount;
	std::cout << "DiamondTrap " << m_name << " takes " << amount << " damage!\n";
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << m_name
			  << ", ClapTrap name: " << ClapTrap::m_name << std::endl;
}
