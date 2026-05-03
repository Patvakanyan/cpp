#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <limits>
#include <vector>
#include <stdexcept>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

private:
	std::vector<int> numbers;
	unsigned int maxSize;
};
#endif
