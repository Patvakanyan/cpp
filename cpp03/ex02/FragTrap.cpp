#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	std::cout << "FragTrap default constructor call" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout << "Constructor with name called for FragTrap " << m_name << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "Copy constructor called for FragTrap " << src.m_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor call" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Copy assignment operator called for FragTrap " << src.m_name << std::endl;
	if(this == &src)
		return *this;
	ClapTrap::operator=(src);
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if(m_energyPoints < 1 || m_hitPoints < 1)
	{
		std::cout << "FragTrap " << m_name << " cannot attack.\n";
		return ;
	}
	--m_energyPoints;
	std::cout << "FragTrap " << m_name << " attacks " << target
		<< ", causing " << m_attackDamage << " points of damage!\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (m_hitPoints <= 0 || m_energyPoints <= 0) {
		std::cout << "FragTrap " << m_name << " cannot repair.\n";
		return;
	}
	m_hitPoints += amount;
	m_energyPoints--;
	std::cout << "FragTrap " << m_name << " repairs itself for "
		<< amount << " hit points!\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount >= m_hitPoints)
		m_hitPoints = 0;
	else
		m_hitPoints -= amount;
	std::cout << "FragTrap " << m_name << " takes " << amount << " damage!\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << m_name << " says: High-fives, guys?" << std::endl;
}
