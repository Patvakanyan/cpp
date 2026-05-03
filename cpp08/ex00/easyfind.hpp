#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &conteiner, const int n)
{
	typename T::iterator it = std::find(conteiner.begin(), conteiner.end(), n);
	if (it == conteiner.end())
		throw std::out_of_range("Element not found");
	return it;
}

#endif
