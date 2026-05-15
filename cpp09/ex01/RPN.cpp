#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		m_stack = other.m_stack;
	}
	return *this;
}

RPN::RPN(const RPN &other) : m_stack(other.m_stack)
{
}

void RPN::operatorApplay(char op)
{
	if (m_stack.size() < 2)
		throw std::invalid_argument("Not enough operands in the stack.");

	int second = m_stack.top();
	m_stack.pop();
	int first = m_stack.top();
	m_stack.pop();
	if (op == '+')
		m_stack.push(first + second);
	else if (op == '-')
		m_stack.push(first - second);
	else if (op == '*')
		m_stack.push(first * second);
	else if (op == '/')
	{
		if (second == 0)
			throw std::invalid_argument("Division by zero occured.");
		m_stack.push(first / second);
	}
}

void RPN::calculate(const std::string &expression)
{
	std::istringstream str(expression);
	std::string token;

	while (str >> token)
	{
		if (token.size() == 1 && isdigit(token[0]))
			m_stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
			operatorApplay(token[0]);
		else
			throw std::runtime_error("Invalid token: " + token);
	}

	if (m_stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	std::cout << m_stack.top() << std::endl;
}
