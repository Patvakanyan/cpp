#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(i);
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Element found: " << *it << '\n';
		it = easyfind(v, 6);
	}
	catch (...)
	{
		std::cerr << "An error occurred." << '\n';
	}

	return 0;
}
