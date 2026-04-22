#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *m_arr;
	unsigned int m_size;

public:
	Array();
	Array(const Array &other);
	Array &operator=(const Array &other);
	unsigned int size() const;
	Array(unsigned int n);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	~Array();
};

#include "Array.tpp"

#endif
