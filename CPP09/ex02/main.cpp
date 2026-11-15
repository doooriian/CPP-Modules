#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	PmergeMe	pmerge;

	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments." << std::endl;
		return (1);
	}
	try
	{
		pmerge.parse(argc, argv);
		pmerge.run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
