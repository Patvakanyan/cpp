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
			throw std::invalid_argument("Invalid input");
		if (val < 0 || val > std::numeric_limits<int>::max())
			throw std::out_of_range("Input out of range");
		if (errno == ERANGE)
			throw std::out_of_range("Input out of range");
		addNumber(static_cast<int>(val));
	}
}

static size_t jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	size_t prev = 0, curr = 1, next = 0;
	for (size_t i = 2; i <= n; ++i)
	{
		next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return curr;
}

static std::vector<size_t> generate_jacobsthal_sequence(size_t pending_size)
{
	std::vector<size_t> sequence;
	if (pending_size == 0)
		return sequence;

	sequence.push_back(0);
	size_t prev_j = 1;
	size_t k = 2;

	while (prev_j < pending_size)
	{
		size_t curr_j = jacobsthal(k);
		size_t start = (curr_j > pending_size) ? pending_size : curr_j;

		for (size_t i = start; i > prev_j; --i)
			sequence.push_back(i - 1);
		prev_j = curr_j;
		k++;
	}
	return sequence;
}

static void sort_pairs(std::vector<std::pair<int, int> > &pairs, size_t left, size_t right)
{
	if (pairs.empty())
		return;

	if (left < right)
	{
		size_t mid = left + (right - left) / 2;
		sort_pairs(pairs, left, mid);
		sort_pairs(pairs, mid + 1, right);
		std::vector<std::pair<int, int> > temp(right - left + 1);
		size_t i = left, j = mid + 1, k = 0;
		while (i <= mid && j <= right)
		{
			if (pairs[i].first < pairs[j].first)
				temp[k++] = pairs[i++];
			else
				temp[k++] = pairs[j++];
		}
		while (i <= mid)
			temp[k++] = pairs[i++];
		while (j <= right)
			temp[k++] = pairs[j++];
		for (size_t l = 0; l < temp.size(); ++l)
			pairs[left + l] = temp[l];
	}
}

void PmergeMe::sortVector()
{
	if (_vector.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	bool has_pending = false;
	int straggler = 0;

	for (size_t i = 0; i + 1 < _vector.size(); i += 2)
	{
		if (_vector[i] > _vector[i + 1])
			pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		else
			pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
	}
	if (_vector.size() % 2 == 1)
	{
		has_pending = true;
		straggler = _vector.back();
	}
	sort_pairs(pairs, 0, pairs.size() - 1);
	std::vector<int> sorted_vector;
	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		sorted_vector.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}

	if (has_pending)
		pending.push_back(straggler);

	if (!pending.empty())
		sorted_vector.insert(sorted_vector.begin(), pending[0]);

	std::vector<size_t> sequence = generate_jacobsthal_sequence(pending.size());

	for (size_t i = 1; i < sequence.size(); ++i)
	{
		int element = pending[sequence[i]];
		std::vector<int>::iterator it = std::lower_bound(sorted_vector.begin(), sorted_vector.end(), element);
		sorted_vector.insert(it, element);
	}

	_vector = sorted_vector;
}

void PmergeMe::sort()
{
	clock_t start_vector = clock();
	sortVector();
	clock_t end_vector = clock();
	double elapsed_vector = double(end_vector - start_vector) * 1000000.0 / CLOCKS_PER_SEC;

	clock_t start_deque = clock();
	sortDeque();
	clock_t end_deque = clock();
	double elapsed_deque = double(end_deque - start_deque) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "After:  ";
	printVector();
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << elapsed_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << elapsed_deque << " us" << std::endl;
}

static void sort_pairs_deque(std::deque<std::pair<int, int> > &pairs, size_t left, size_t right)
{
	if (pairs.empty())
		return;

	if (left < right)
	{
		size_t mid = left + (right - left) / 2;
		sort_pairs_deque(pairs, left, mid);
		sort_pairs_deque(pairs, mid + 1, right);
		std::deque<std::pair<int, int> > temp(right - left + 1);
		size_t i = left, j = mid + 1, k = 0;
		while (i <= mid && j <= right)
		{
			if (pairs[i].first < pairs[j].first)
				temp[k++] = pairs[i++];
			else
				temp[k++] = pairs[j++];
		}
		while (i <= mid)
			temp[k++] = pairs[i++];
		while (j <= right)
			temp[k++] = pairs[j++];
		for (size_t l = 0; l < temp.size(); ++l)
			pairs[left + l] = temp[l];
	}
}

void PmergeMe::sortDeque()
{
	if (_deque.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	bool has_pending = false;
	int straggler = 0;

	for (size_t i = 0; i + 1 < _deque.size(); i += 2)
	{
		if (_deque[i] > _deque[i + 1])
			pairs.push_back(std::make_pair(_deque[i], _deque[i + 1]));
		else
			pairs.push_back(std::make_pair(_deque[i + 1], _deque[i]));
	}
	if (_deque.size() % 2 == 1)
	{
		has_pending = true;
		straggler = _deque.back();
	}

	sort_pairs_deque(pairs, 0, pairs.size() - 1);

	std::deque<int> sorted_deque;
	std::deque<int> pending;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		sorted_deque.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}

	if (has_pending)
		pending.push_back(straggler);

	if (!pending.empty())
		sorted_deque.insert(sorted_deque.begin(), pending[0]);

	std::vector<size_t> sequence = generate_jacobsthal_sequence(pending.size());

	for (size_t i = 1; i < sequence.size(); ++i)
	{
		int element = pending[sequence[i]];
		std::deque<int>::iterator it = std::lower_bound(sorted_deque.begin(), sorted_deque.end(), element);
		sorted_deque.insert(it, element);
	}

	_deque = sorted_deque;
}
