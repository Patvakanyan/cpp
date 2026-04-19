#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	Base *base = generate();
	std::cout << "Identify by pointer: ";
	identify(base);
	std::cout << "Identify by reference: ";
	identify(*base);
	delete base;
	return 0;
}
