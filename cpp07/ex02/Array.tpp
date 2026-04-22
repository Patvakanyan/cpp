#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_arr(NULL), m_size(0)
{
}
template <typename T>
Array<T>::Array(unsigned int n) : m_arr(new T[n]), m_size(n)
{
}
template <typename T>
Array<T>::Array(const Array<T> &other) : m_size(other.m_size)
{
	m_arr = new T[m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		m_arr[i] = other.m_arr[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		T *new_arr = new T[other.m_size];
		for (size_t i = 0; i < other.m_size; i++)
			new_arr[i] = other.m_arr[i];
		delete[] m_arr;
		m_arr = new_arr;
		m_size = other.m_size;
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return m_size;
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_arr[index];
}
#endif
