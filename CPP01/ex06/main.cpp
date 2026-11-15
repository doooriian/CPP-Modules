#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Please enter one of the following levels: "
		<< "\"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\"" << std::endl
		<< "For example: ./harlFilter \"WARNING\"" << std::endl;
		return (1);
	}
	Harl	h;
	h.complain(argv[1]);
	return (0);
}