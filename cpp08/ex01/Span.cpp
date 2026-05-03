#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (numbers.size() + 1 > maxSize)
		throw std::out_of_range("Span is already full");
	numbers.push_back(number);
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough elements to find a span.");
	return (*std::max_element(numbers.begin(), numbers.end()) -
			*std::min_element(numbers.begin(), numbers.end()));
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough elements to find a span.");
	std::vector<int> sortedNumbers(numbers);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

