#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

class RPN
{
	private:
		std::stack<int> _stack;

		bool isOperator(const std::string& token) const;
		bool isNumber(const std::string& token) const;
		int applyOperator(int a, int b, const std::string& op) const;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int evaluate(const std::string& expression);
};

#endif