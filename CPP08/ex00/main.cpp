#include "easyfind.hpp"
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>

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
	printSectionHeader("BASIC TESTS");
	std::cout << YELLOW;
	std::list<int>		lst;
	std::vector<int>	vec;
	std::list<int>::const_iterator	it_lst;
	std::vector<int>::const_iterator	it_vec;
	for (int i = 1; i <= 10; ++i)
	{
		lst.push_back(i);
		vec.push_back(i);
	}
	it_lst = easyfind(lst, 4);
	it_vec = easyfind(vec, 2);
	std::cout << "Lst and vec are two containers respectively a list and a vector, containing numbers from 1 to 10" << std::endl;
	std::cout << "We are looking for the number 4 in lst, and the number 2 in vec" << std::endl;
	std::cout << "Result:" << std::endl << "it_lst = " << *it_lst << std::endl << "it_vec = " << *it_vec << std::endl;

	printSectionHeader("EXCEPTIONS TESTS");
	std::cout << GREEN;
	try
	{
		easyfind(lst, 11);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catch for lst: " << e.what() << std::endl;
	}
	try
	{
		easyfind(vec, 42);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catch for vec: " << e.what() << std::endl;
	}
	std::list<int>	empty;
	try
	{
		easyfind(empty, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catch for empty list: " << e.what() << std::endl;
	}
	std::cout << RESET;
	return (0);
}
