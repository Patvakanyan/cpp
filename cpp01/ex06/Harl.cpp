#include "Harl.hpp"


Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level){
	std::string levels[] = {"DEBUG","INFO","WARNING","ERROR"};
	size_t i;
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break;
	}
	switch (i)
	{
	case 0:
		debug();
		/* fall through */
	case 1:
		info();
		/* fall through */
	case 2:
		warning();
		/* fall through */
	case 3:
		error();
		break;
	default:
		std::cout << "unrecognized level" << std::endl;
	}
}
