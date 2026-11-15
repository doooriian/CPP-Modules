#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	RPN		rpn;
	long	result;
	try
	{
		result = rpn.evaluate(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	std::cout << result << std::endl;
	return (0);
}
