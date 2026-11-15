#pragma once
#include <stack>
#include <string>

class	RPN
{
	public:

		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);

		long	evaluate(const std::string &expression);

	private:

		std::stack<long>	_stack;
		void				check_add(long first, long second);
		void				check_sub(long first, long second);
		void				check_mult(long first, long second);
		void				check_div(long first, long second);
		long				calculate(const char &token);
};
