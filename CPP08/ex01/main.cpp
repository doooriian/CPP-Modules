#include "Span.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <cstdlib>	// rand()
#include <ctime>	// time()

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void printSectionHeader(const std::string& title)
{
	std::cout << std::endl << BOLD << BLUE
		<< "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE
		<< "║ " << std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
	std::cout << BOLD << BLUE
		<< "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	printSectionHeader("BASIC TESTS");
	std::cout << YELLOW;

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Span contains: 6, 3, 17, 9, 11\n";
	std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span  = " << sp.longestSpan() << std::endl;

	printSectionHeader("EXCEPTIONS TESTS");
	std::cout << GREEN;

	try {
		sp.addNumber(42);
	}
	catch (std::exception &e) {
		std::cout << "Exception catched on addNumber : " << e.what() << std::endl;
	}

	try {
		Span empty(2);
		empty.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << "Exception catched on shortestSpan: " << e.what() << std::endl;
	}

	try {
		Span one(2);
		one.addNumber(1);
		one.longestSpan(); // not enough
	}
	catch (std::exception &e) {
		std::cout << "Exception catched on longestSpan: " << e.what() << std::endl;
	}

	printSectionHeader("ADD RANGE TESTS");
	std::cout << CYAN;

	std::vector<int> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(i * 10);

	Span sp2(10);
	sp2.addRange(vec.begin(), vec.end());

	std::cout << "sp2 filled using addRange with values: 0, 10, 20, 30, 40\n";
	std::cout << "Shortest span = " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span  = " << sp2.longestSpan() << std::endl;

	try {
		sp2.addRange(vec.begin(), vec.end());
	}
	catch (std::exception &e) {
		std::cout << "Exception catched on addRange: " << e.what() << std::endl;
	}

	printSectionHeader("LARGE SPAN TEST (10,000 numbers)");
	std::cout << GREEN;

	Span big(10000);
	std::vector<int> huge;
	for (int i = 0; i < 10000; ++i)
		huge.push_back(std::rand());

	big.addRange(huge.begin(), huge.end());

	std::cout << "Shortest span (random 10k) = " << big.shortestSpan() << std::endl;
	std::cout << "Longest span  (random 10k) = " << big.longestSpan() << std::endl;

	std::cout << RESET << std::endl;

	return (0);
}
