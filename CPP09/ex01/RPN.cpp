#include "RPN.hpp"
#include <cctype>
#include <climits>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
: _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

void	RPN::check_add(long first, long second)
{
	if ((second > 0 && first > LONG_MAX - second) || (second < 0 && first < LONG_MIN - second))
		throw std::runtime_error("Error: result out of range");
}

void	RPN::check_sub(long first, long second)
{
	if ((second < 0 && first > LONG_MAX + second) || (second > 0 && first < LONG_MIN + second))
		throw std::runtime_error("Error: result out of range");
}

void	RPN::check_mult(long first, long second)
{
	if (first == 0 || second == 0)
		return;
	if ((first == -1 && second == LONG_MIN) || (second == -1 && first == LONG_MIN))
		throw std::runtime_error("Error: result out of range");
	if (first > 0)
	{
		if (second > 0 && first > LONG_MAX / second)
			throw std::runtime_error("Error: result out of range");
		if (second < 0 && second < LONG_MIN / first)
			throw std::runtime_error("Error: result out of range");
	}
	else
	{
		if (second > 0 && first < LONG_MIN / second)
			throw std::runtime_error("Error: result out of range");
		if (second < 0 && first < LONG_MAX / second)
			throw std::runtime_error("Error: result out of range");
	}
}

void	RPN::check_div(long first, long second)
{
	if (second == 0)
		throw std::runtime_error("Error: can't divide by 0");
	if (second == -1 && first == LONG_MIN)
		throw std::runtime_error("Error: result out of range");
}

long	RPN::calculate(const char &token)
{
	long	second;
	long	first;

	if (this->_stack.size() < 2)
		throw std::runtime_error("Error: stack underflow (need 2 operands to apply an operator)");
	second = this->_stack.top();
	this->_stack.pop();
	first = this->_stack.top();
	this->_stack.pop();
	switch (token)
	{
		case '+':
		check_add(first, second);
		return (first + second);
		case '-':
		check_sub(first, second);
		return (first - second);
		case '*':
		check_mult(first, second);
		return (first * second);
		case '/':
		check_div(first, second);
		return (first / second);
	}
	throw std::runtime_error("Error");
}

static bool	isOperatorToken(const char &token)
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

static bool	isDigitToken(const char &token)
{
	return (std::isdigit(static_cast<unsigned char>(token)));
}

long	RPN::evaluate(const std::string &expression)
{
	std::string::const_iterator	it = expression.begin();
	std::string::const_iterator	ite = expression.end();

	while (!this->_stack.empty())
		this->_stack.pop();
	for (; it != ite; ++it)
	{
		if (isDigitToken(*it))
			this->_stack.push(*it - '0');
		else if (isOperatorToken(*it))
			this->_stack.push(calculate(*it));
		else if (std::isspace(static_cast<unsigned char>(*it)))
			continue;
		else
			throw std::runtime_error(std::string("Error: unrecognized token '") + *it + "'");
	}
	if (this->_stack.empty())
		throw std::runtime_error("Error: no result (stack empty)");
	if (this->_stack.size() != 1)
		throw std::runtime_error("Error: invalid result (pending operands)");
	return (this->_stack.top());

}
