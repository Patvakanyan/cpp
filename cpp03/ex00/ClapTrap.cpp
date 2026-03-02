#include "ClapTrap.hpp"

ClapTrap::ClapTrap():m_name("default"), m_hitPoints(10),
	m_energyPoints(10), m_attackDamage(0){
	std::cout<< "Default constructor called" << std::endl;
}
ClapTrap::~ClapTrap(){
	std::cout<< "Destructor called for " << m_name << std::endl;
}

ClapTrap::ClapTrap(std::string name):m_name(name), m_hitPoints(10),
	m_energyPoints(10), m_attackDamage(0)
{
	std::cout<< "Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src): m_name(src.m_name), m_hitPoints(src.m_hitPoints),
	m_energyPoints(src.m_energyPoints), m_attackDamage(src.m_attackDamage)
{
	std::cout<< "Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	std::cout<< "Copy assignment operator called" << std::endl;
	if(this == &src )
		return *this;
	m_name = src.m_name;
	m_attackDamage = src.m_attackDamage;
	m_energyPoints = src.m_energyPoints;
	m_hitPoints = src.m_hitPoints;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if(m_energyPoints < 1 || m_hitPoints < 1)
	{
		std::cout << "ClapTrap " << m_name << " cannot attack.\n";
		return ;
	}
	--m_energyPoints;
	std::cout << "ClapTrap " << m_name << " attacks " << target
		<< ", causing " << m_attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= m_hitPoints)
		m_hitPoints = 0;
	else
		m_hitPoints -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount << " damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (m_hitPoints <= 0 || m_energyPoints <= 0) {
		std::cout << "ClapTrap " << m_name << " cannot repair.\n";
		return;
	}
	m_hitPoints += amount;
	m_energyPoints--;
	std::cout << "ClapTrap " << m_name
		<< " repairs itself for "
		<< amount << " hit points!\n";
}
