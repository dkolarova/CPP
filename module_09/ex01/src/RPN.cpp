#include <RPN.hpp>

// ---------------- ORTX-CANONICAL FORM

RPN::RPN(){}

RPN::RPN(const RPN& other)
{
	_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

// ---------------- HELPERS

bool RPN::isNumber(const std::string& token) const
{
	if (token.length() != 1)
		return false;

	return (token[0] >= '0' && token[0] <= '9');
}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperator(int a, int b, const std::string& op) const
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return a / b;
	}
	throw std::runtime_error("Unknown operator");
}

// 

int RPN::evaluate(const std::string& expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (isNumber(token))
		{
			_stack.push(std::atoi(token.c_str()));
		}
	}

	return 0;
}
