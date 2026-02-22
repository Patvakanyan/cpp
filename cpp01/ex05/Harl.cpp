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
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears,whereas you started working here just last month.\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level){
	std::string levels[] = {"DEBUG","INFO","WARNING","ERROR"};
	void (Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	(this->*funcs[0])();
}
