#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor call" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain  destructor call" << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		m_ideas[i] = src.m_ideas[i];
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			m_ideas[i] = src.m_ideas[i];
	}
	return *this;
}
