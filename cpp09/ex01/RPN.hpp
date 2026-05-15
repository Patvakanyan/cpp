#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>

class RPN {
public:
	RPN();
	~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	void calculate(const std::string& expression);
	void operatorApplay(char op);
private:
	std::stack<int> m_stack;
};

#endif
