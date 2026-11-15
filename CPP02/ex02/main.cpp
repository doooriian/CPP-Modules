#include "Fixed.hpp"
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

int	main(void)
{
	printSectionHeader("BASIC TESTS FROM SUBJECT");
	
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << YELLOW << "a: " << RESET << a << std::endl;
	std::cout << YELLOW << "++a: " << RESET << ++a << std::endl;
	std::cout << YELLOW << "a: " << RESET << a << std::endl;
	std::cout << YELLOW << "a++: " << RESET << a++ << std::endl;
	std::cout << YELLOW << "a: " << RESET << a << std::endl;
	std::cout << YELLOW << "b: " << RESET << b << std::endl;
	std::cout << YELLOW << "max(a,b): " << RESET << Fixed::max(a, b) << std::endl;
	
	printSectionHeader("ADDITIONAL TESTS");
	
	Fixed c(42.42f);
	Fixed d(10);
	Fixed e(d);
	
	std::cout << CYAN << "CONSTRUCTORS & ASSIGNMENTS:" << RESET << std::endl;
	std::cout << GREEN << "c(42.42f): " << RESET << c << std::endl;
	std::cout << GREEN << "d(10): " << RESET << d << std::endl;
	std::cout << GREEN << "e(d): " << RESET << e << std::endl;
	
	printSectionHeader("INTEGER/FLOAT CONVERSION");
	std::cout << MAGENTA << "c as int: " << RESET << c.toInt() << std::endl;
	std::cout << MAGENTA << "d as float: " << RESET << d.toFloat() << std::endl;
	
	printSectionHeader("COMPARISON OPERATORS");
	std::cout << CYAN << "c > d: " << RESET << (c > d ? "true" : "false") << std::endl;
	std::cout << CYAN << "c < d: " << RESET << (c < d ? "true" : "false") << std::endl;
	std::cout << CYAN << "d >= e: " << RESET << (d >= e ? "true" : "false") << std::endl;
	std::cout << CYAN << "d <= e: " << RESET << (d <= e ? "true" : "false") << std::endl;
	std::cout << CYAN << "d == e: " << RESET << (d == e ? "true" : "false") << std::endl;
	std::cout << CYAN << "c != d: " << RESET << (c != d ? "true" : "false") << std::endl;
	
	printSectionHeader("ARITHMETIC OPERATORS");
	std::cout << GREEN << "c + d = " << RESET << (c + d) << std::endl;
	std::cout << GREEN << "c - d = " << RESET << (c - d) << std::endl;
	std::cout << GREEN << "c * d = " << RESET << (c * d) << std::endl;
	std::cout << GREEN << "c / d = " << RESET << (c / d) << std::endl;
	
	printSectionHeader("INCREMENT/DECREMENT OPERATORS");
	Fixed f(0.5f);
	std::cout << YELLOW << "f(0.5f): " << RESET << f << std::endl;
	std::cout << YELLOW << "++f: " << RESET << ++f << " (pre-increment)" << std::endl;
	std::cout << YELLOW << "f: " << RESET << f << " (after pre-increment)" << std::endl;
	std::cout << YELLOW << "f++: " << RESET << f++ << " (post-increment)" << std::endl;
	std::cout << YELLOW << "f: " << RESET << f << " (after post-increment)" << std::endl;
	std::cout << YELLOW << "--f: " << RESET << --f << " (pre-decrement)" << std::endl;
	std::cout << YELLOW << "f: " << RESET << f << " (after pre-decrement)" << std::endl;
	std::cout << YELLOW << "f--: " << RESET << f-- << " (post-decrement)" << std::endl;
	std::cout << YELLOW << "f: " << RESET << f << " (after post-decrement)" << std::endl;
	
	printSectionHeader("MIN/MAX FUNCTIONS");
	std::cout << MAGENTA << "min(c, d): " << RESET << Fixed::min(c, d) << std::endl;
	std::cout << MAGENTA << "max(c, d): " << RESET << Fixed::max(c, d) << std::endl;
	
	const Fixed g(123.456f);
	const Fixed h(123.456f);
	std::cout << MAGENTA << "const g(123.456f): " << RESET << g << std::endl;
	std::cout << MAGENTA << "const h(123.456f): " << RESET << h << std::endl;
	std::cout << MAGENTA << "min(g, h): " << RESET << Fixed::min(g, h) << std::endl;
	std::cout << MAGENTA << "max(g, h): " << RESET << Fixed::max(g, h) << std::endl;
	
	printSectionHeader("DIVISION BY ZERO");
	std::cout << RED << "Division by zero (program may crash):" << RESET << std::endl;
	Fixed zero;
	std::cout << RED << "Division by zero test skipped to prevent program crash" << RESET << std::endl;
	
	printSectionHeader("END OF TESTS");
	
	return (0);
}

// int main()
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
	
// 	std::cout << b << std::endl;
	
// 	std::cout << Fixed::max( a, b ) << std::endl;
	
// 	return (0);
// }