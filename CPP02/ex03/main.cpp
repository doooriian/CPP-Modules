#include "Point.hpp"
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

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	printSectionHeader(const std::string& title)
{
	std::cout << std::endl << BOLD << BLUE << "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE << "║ " << std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
	std::cout << BOLD << BLUE << "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
}

void	print_result(const Point a, const Point b, const Point c, const Point p)
{
	if (bsp(a, b, c, p) == 1)
		std::cout << GREEN << "TRUE" << RESET << std::endl;
	else
		std::cout << RED << "FALSE" << RESET << std::endl;
}

int	main(void)
{
	printSectionHeader("POINT INSIDE");
	{
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 10);
		Point p(3, 3);

		std::cout << YELLOW << "a = (0, 0)\nb = (10, 0)\nc = (0, 10)\n"
		"point = (3, 3)\n\nresult = " << RESET;
		print_result(a, b, c, p);
	}
	printSectionHeader("POINT ON A VERTEX");
	{
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 10);
		Point p(0, 0);

		std::cout << MAGENTA << "a = (0, 0)\nb = (10, 0)\nc = (0, 10)\n"
		"point = (0, 0)\n\nresult = " << RESET;
		print_result(a, b, c, p);
	}
	printSectionHeader("POINT ON AN EDGE");
	{
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 10);
		Point p(5, 0);

		std::cout << CYAN << "a = (0, 0)\nb = (10, 0)\nc = (0, 10)\n"
		"point = (5, 0)\n\nresult = " << RESET;
		print_result(a, b, c, p);
	}
	printSectionHeader("POINT OUTSIDE");
	{
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 10);
		Point p(10, 10);

		std::cout << YELLOW << "a = (0, 0)\nb = (10, 0)\nc = (0, 10)\n"
		"point = (10, 10)\n\nresult = " << RESET;
		print_result(a, b, c, p);
	}
	printSectionHeader("SCALENE TRIANGLE");
	{
		Point a(1, 1);
		Point b(5, 2);
		Point c(2, 6);
		Point p1(3, 3);
		Point p2(4, 5);

		std::cout << MAGENTA << "a = (1, 1)\nb = (5, 2)\nc = (2, 6)\n"
		"point n1 = (3, 3) -> " << GREEN << "inside" << MAGENTA <<
		"\npoint n2 = (4, 5) -> " << RED << "outside" << MAGENTA <<
		"\np1 result = " << RESET;
		print_result(a, b, c, p1);
		std::cout << MAGENTA << "p2 result = " << RESET;
		print_result(a, b, c, p2);
	}
	printSectionHeader("CLOSE TO THE EDGE");
	{
		Point a(0, 0);
		Point b(5, 0);
		Point c(0, 5);
		Point p1(2.5, 2.49);
		Point p2(2.5, 2.5);

		std::cout << CYAN << "a = (0, 0)\nb = (5, 0)\nc = (0, 5)\n"
		"point n1 = (2.5, 2.49) -> " << GREEN << "inside" << CYAN <<
		"\npoint n2 = (2.5, 2.5) -> " << RED << "on diagonal" << CYAN <<
		"\np1 result = " << RESET;
		print_result(a, b, c, p1);
		std::cout << CYAN << "p2 result = " << RESET;
		print_result(a, b, c, p2);
	}
	printSectionHeader("CLOCK WISE TRIANGLE");
	{
		Point a(0, 0);
		Point b(0, 10);
		Point c(10, 0);
		Point p1(3, 3);
		Point p2(10, 10);

		std::cout << YELLOW << "a = (0, 0)\nb = (0, 10)\nc = (10, 0)\n"
		"point n1 = (3, 3) -> " << GREEN << "inside" << YELLOW <<
		"\npoint n2 = (10, 10) -> " << RED << "outside" << YELLOW <<
		"\np1 result = " << RESET;
		print_result(a, b, c, p1);
		std::cout << YELLOW << "p2 result = " << RESET;
		print_result(a, b, c, p2);
	}
	printSectionHeader("END OF TESTS");
	
	return (0);
}
