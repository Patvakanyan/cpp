#ifndef INTER_HPP
#define INTER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *arr, const size_t size, void f(T &))
{
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

template <typename T>
void print(T &item)
{
	std::cout << item << std::endl;
}

template <typename T>
void pow(T &item)
{
	size_t degree = 2;
	while (--degree)
		item *= item;
}

#endif
