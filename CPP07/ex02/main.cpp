#include "Array.hpp"
#include <iostream>
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void	printSectionHeader(const std::string& title)
{
	std::cout << std::endl << BOLD << BLUE << "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE << "║ " << std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
	std::cout << BOLD << BLUE << "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
}

int	main(void)
{
	printSectionHeader("CONSTRUCTORS");
	std::cout << YELLOW;
	Array<long> empty;
	Array<char>	typeC(5);
	Array<int>	typeInt(2);

	printSectionHeader("BASIC TESTS");
	std::cout << GREEN;
	typeC[0] = 'H';
	typeC[1] = 'e';
	typeC[2] = 'l';
	typeC[3] = 'l';
	typeC[4] = 'o';
	typeInt[0] = 4;
	typeInt[1] = 2;
	std::cout << "typeC size: " << typeC.size() << std::endl;
	std::cout << "typeC content: " << typeC << std::endl;
	std::cout << "typeInt size: " << typeInt.size() << std::endl;
	std::cout << "typeInt content: " << typeInt << std::endl;

	printSectionHeader("EXCEPTION TESTS");
	std::cout << CYAN;
	try
	{
		empty[0] = 1;
	}
	catch (std::exception	&e)
	{
		std::cerr << "Exception catch: " << e.what() << std::endl;
	}
	try
	{
		typeC[5] = 42;
	}
	catch (std::exception	&e)
	{
		std::cerr << "Exception catch: " << e.what() << std::endl;
	}
	try
	{
		typeInt[42] = -1;
	}
	catch (std::exception	&e)
	{
		std::cerr << "Exception catch: " << e.what() << std::endl;
	}

	printSectionHeader("COPY CONSTRUCTOR TEST");
	std::cout << YELLOW;
	Array<char>	copyC(typeC);
	std::cout << "Before changing copyC:" << std::endl;
	std::cout << "typeC: " << typeC << std::endl;
	std::cout << "copyC: " << copyC << std::endl << std::endl;
	copyC[0] = 'a';
	copyC[1] = 'b';
	copyC[2] = 'c';
	copyC[3] = 'd';
	copyC[4] = 'e';
	std::cout << "After changing copyC:" << std::endl;
	std::cout << "typeC: " << typeC << std::endl;
	std::cout << "copyC: " << copyC << std::endl;

	printSectionHeader("ASSIGNMENT OPERATOR TEST");
	std::cout << GREEN;
	Array<int> copyInt(4);
	copyInt[0] = 1;
	copyInt[1] = 2;
	copyInt[2] = 3;
	copyInt[3] = 4;
	std::cout << "Before assigning typeInt to copyInt:" << std::endl;
	std::cout << "typeInt: " << typeInt << std::endl;
	std::cout << "copyInt: " << copyInt << std::endl << std::endl;
	copyInt = typeInt;
	std::cout << "After assigning typeInt to copyInt:" << std::endl;
	std::cout << "typeInt: " << typeInt << std::endl;
	std::cout << "copyInt: " << copyInt << std::endl << std::endl;
	copyInt[0] = 2;
	copyInt[1] = 4;
	std::cout << "And after modifying copyInt:" << std::endl;
	std::cout << "typeInt: " << typeInt << std::endl;
	std::cout << "copyInt: " << copyInt << std::endl << std::endl;


	printSectionHeader("DESTRUCTORS");
	std::cout << GREEN;

	return (0);
}
