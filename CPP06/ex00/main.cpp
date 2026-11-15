#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	std::string	input = argv[1];
	ScalarConverter::convert(input);
	return (0);
}

// #include "ScalarConverter.hpp"
// #include <iostream>
// #include <iomanip>

// #define RESET	"\033[0m"
// #define RED		"\033[31m"
// #define GREEN	"\033[32m"
// #define YELLOW	"\033[33m"
// #define BLUE	"\033[34m"
// #define MAGENTA	"\033[35m"
// #define CYAN	"\033[36m"
// #define BOLD	"\033[1m"


// void	printSectionHeader(const std::string& title)
// {
// 	std::cout << std::endl << BOLD << BLUE
// 		<< "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
// 	std::cout << BOLD << BLUE << "║ "
// 		<< std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
// 	std::cout << BOLD << BLUE
// 		<< "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
// }

// void printTest(const std::string& literal)
// {
// 	std::cout << YELLOW << "./convert " << literal << GREEN << std::endl;
// 	ScalarConverter::convert(literal);
// 	std::cout << std::endl;
// }


// int	main(void)
// {
// 	printSectionHeader("CHAR TESTS");
// 	printTest("a");
// 	printTest("Z");
// 	printTest("*");
// 	printTest("~");
// 	printTest(" ");
// 	printTest("\t");

// 	printSectionHeader("INT BASIC TESTS");
// 	printTest("0");
// 	printTest("42");
// 	printTest("-42");
// 	printTest("127");	// char max
// 	printTest("31");
// 	printTest("32");

// 	printSectionHeader("INT LIMIT TESTS");
// 	printTest("2147483647");	// int max
// 	printTest("-2147483648");	// int min

// 	printSectionHeader("INT OVER/UNDERFLOW TESTS");
// 	printTest("2147483648");	// overflow (int max + 1)
// 	printTest("-2147483649");	// underflow (int min - 1)

// 	printSectionHeader("FLOAT TESTS");
// 	printTest("0.0f");
// 	printTest("42.0f");
// 	printTest("-42.5f");
// 	printTest("4.2f");


// 	printSectionHeader("DOUBLE TESTS");
// 	printTest("0.0");
// 	printTest("42.0");
// 	printTest("-42.5");
// 	printTest("4.2");

// 	printSectionHeader("PSEUDO-LITERALS");
// 	printTest("nan");
// 	printTest("nanf");
// 	printTest("+inf");
// 	printTest("-inf");
// 	printTest("+inff");
// 	printTest("-inff");

// 	printSectionHeader("INVALID TESTS");
// 	printTest("42f");
// 	printTest("4.2ff");
// 	printTest("4..2");
// 	printTest("4.2.1");
// 	printTest("abc");
// 	printTest("nanff");
// 	printTest("+infz");
// 	printTest("--42");
// 	printTest("++42");

// 	return (0);
// }
