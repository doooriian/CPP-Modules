#include "Bureaucrat.hpp"
#include <iostream>
#include <iomanip>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define BOLD	"\033[1m"


void	printSectionHeader(const std::string& title)
{
	std::cout << std::endl << BOLD << BLUE << "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE << "║ " << std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
	std::cout << BOLD << BLUE << "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
}

int	main(void)
{
	printSectionHeader("CONSTRUCTORS");
	std::cout << GREEN;
	Bureaucrat	Random;
	Bureaucrat	Random2(1);
	Bureaucrat	John("John");
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Trainee("Trainee", 150);
	Bureaucrat	BigBoss = Boss;

	printSectionHeader("PRINT VARIABLES WITH '<<' OPERATOR");
	std::cout << YELLOW;
	std::cout << Random << std::endl;
	std::cout << Random2 << std::endl;
	std::cout << John << std::endl;
	std::cout << Boss << std::endl;
	std::cout << Trainee << std::endl;
	std::cout << BigBoss << std::endl;

	printSectionHeader("INVALID GRADE IN CONSTRUCTOR");
	std::cout << CYAN;
	try
	{
		Bureaucrat TooLow("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat TooHigh("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


	printSectionHeader("EXCEPTIONS ERROR");
	std::cout << GREEN;
	std::cout << "Try to promote Boss: 1 -> 0 must be an exception" << std::endl;
	std::cout << RED;
	try
	{
		Boss.promote();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << GREEN;
	std::cout << "Try to demote Trainee: 150 -> 151 must be an exception" << std::endl;
	std::cout << RED;
	try
	{
		Trainee.demote();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printSectionHeader("PROMOTE AND DEMOTE");
	std::cout << MAGENTA;
	std::cout << "Try to demote Boss: 1 -> 2 must not be an exception" << std::endl;
	std::cout << "Try to demote Trainee: 150 -> 149 must not be an exception" << std::endl;
	try
	{
		Boss.demote();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Trainee.promote();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << GREEN;
	std::cout << "Result after promote: " << std::endl;
	std::cout << MAGENTA;
	std::cout << Boss << std::endl;
	std::cout << Trainee << std::endl;

	printSectionHeader("DESTRUCTORS");
	return (0);
}
