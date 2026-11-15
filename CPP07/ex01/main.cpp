#include "iter.hpp"
#include <iostream>
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void	printSectionHeader(const std::string& title)
{
	std::cout << std::endl << BOLD << BLUE << "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE << "║ " << std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
	std::cout << BOLD << BLUE << "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
}

void	increment(int &n)
{
	n++;
}

void	to_upper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void	print_num(const int *array, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void	print_str(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		std::cout << str[i];
	std::cout << std::endl;
}

template<typename T>
void	print(const T &val)
{
	std::cout << val << " ";
}

int	main(void)
{
	printSectionHeader("NUMERIC ARRAY WITH INCREMENT");
	std::cout << YELLOW;
	int	num[4] = {1, 2, 3, 4};
	std::cout << "Before: ";
	print_num(num, 4);
	iter(num, 4, increment);
	std::cout << "After: ";
	print_num(num, 4);

	printSectionHeader("STRING WITH TO_UPPER");
	std::cout << GREEN;
	char	str[19] = "this IS a TEST 123";
	std::cout << "Before: ";
	print_str(str);
	iter(str, 19, to_upper);
	std::cout << "After: ";
	print_str(str);

	printSectionHeader("TEMPLATE FUNCTION AS THIRD PARAM");
	std::cout << CYAN;
	int arr[5] = {10, 20, 30, 40, 50};
		iter(arr, 5, print<int>);
	std::cout << std::endl;

	printSectionHeader("CONST ARRAY");
	std::cout << MAGENTA;
	const int const_arr[3] = {7, 8, 9};
	iter(const_arr, 3, print<int>);
	std::cout << RESET << std::endl;

	return (0);
}
