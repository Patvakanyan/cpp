#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addNumber(int number)
{
	_vector.push_back(number);
	_deque.push_back(number);
}

void PmergeMe::sort()
{
	std::clock_t start_vector = std::clock();
	sortVector();
	std::clock_t end_vector = std::clock();
	double elapsed_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;

	std::clock_t start_deque = std::clock();
	sortDeque();
	std::clock_t end_deque = std::clock();
	double elapsed_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << elapsed_vector << " seconds" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << elapsed_deque << " seconds" << std::endl;
}

void PmergeMe::printVector() const
{
	for (size_t i = 0; i < _vector.size(); ++i)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
	for (size_t i = 0; i < _deque.size(); ++i)
	{
		std::cout << _deque[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::checkInput(int argc, char **argv)
{
	char *end;

	for (int i = 1; i < argc; ++i)
	{
		errno = 0;
		long val = strtol(argv[i], &end, 10);
		if (*end != '\0')
		{
			throw std::invalid_argument("Invalid input");
		}
		if (val < 0 || val > std::numeric_limits<int>::max())
		{
			throw std::out_of_range("Input out of range");
		}
		if (errno == ERANGE)
		{
			throw std::out_of_range("Input out of range");
		}
		addNumber(static_cast<int>(val));
	}
}
static size_t jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::sortVector()
{
	if (_vector.size() <= 1)
		return;

	std::vector<std::pair<int, int> > main_chain;
	std::vector<std::pair<int, int> > pending_elements;
	for (size_t i = 0; i + 1 < _vector.size(); i += 2)
	{
		if (_vector[i] > _vector[i + 1])
			main_chain.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		else
			main_chain.push_back(std::make_pair(_vector[i + 1], _vector[i]));
	}
	if (_vector.size() % 2 == 1)
		pending_elements.push_back(std::make_pair(_vector.back(), _vector.back()));


}
void PmergeMe::sortDeque()
{
	std::sort(_deque.begin(), _deque.end());
}
