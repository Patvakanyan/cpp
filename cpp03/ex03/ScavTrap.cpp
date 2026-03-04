#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor called for ScavTrap " << m_name << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap " << m_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor with name called for ScavTrap " << m_name << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "Copy constructor called for ScavTrap " << src.m_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Copy assignment operator called for ScavTrap " << src.m_name << std::endl;
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (m_energyPoints < 1 || m_hitPoints < 1)
	{
		std::cout << "ScavTrap " << m_name << " cannot attack.\n";
		return;
	}
	--m_energyPoints;
	std::cout << "ScavTrap " << m_name << " attacks " << target
			  << ", causing " << m_attackDamage << " points of damage!\n";
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (m_hitPoints <= 0 || m_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << m_name << " cannot repair.\n";
		return;
	}
	m_hitPoints += amount;
	m_energyPoints--;
	std::cout << "ScavTrap " << m_name << " repairs itself for "
			  << amount << " hit points!\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount >= m_hitPoints)
		m_hitPoints = 0;
	else
		m_hitPoints -= amount;
	std::cout << "ScavTrap " << m_name << " takes " << amount << " damage!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << m_name << " is now in Gatekeeper mode" << std::endl;
}
