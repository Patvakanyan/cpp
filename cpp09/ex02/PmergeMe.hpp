#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <chrono>
#include <stdexcept>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void addNumber(int number);
	void sort();
	void printVector() const;
	void printDeque() const;
	void checkInput(int argc, char **argv);
private:
	std::vector<int> _vector;
	std::deque<int> _deque;

	void sortVector();
	void sortDeque();
};

#endif
