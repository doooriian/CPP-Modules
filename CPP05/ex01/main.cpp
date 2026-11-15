#include "Bureaucrat.hpp"
#include "Form.hpp"
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
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Trainee("Trainee", 150);
	Form		Contract("Contract", 1, 1);
	Form		PaperWork("PaperWork", 150, 15);

	printSectionHeader("PRINT VARIABLES WITH '<<' OPERATOR");
	std::cout << YELLOW;
	std::cout << Boss << std::endl;
	std::cout << Trainee << std::endl;
	std::cout << Contract << std::endl;
	std::cout << PaperWork << std::endl;

	printSectionHeader("INVALID CONSTRUCTOR");
	std::cout << CYAN;
	try
	{
		Form	TooLow("TooLow", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Form TooHigh("TooHigh", 5, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	printSectionHeader("SIGNING TESTS FROM BUREAUCRAT CLASS");
	std::cout << MAGENTA << "Try to sign Contract with Trainee (must fail)\n" << RED;
	Trainee.signForm(Contract);
	std::cout << MAGENTA << "Try to sign Contract with Boss (must work)\n" << GREEN;
	Boss.signForm(Contract);
	std::cout << MAGENTA << "Try to re-sign Contract with Boss (must fail)\n" << RED;
	Boss.signForm(Contract);

	printSectionHeader("SIGNING TESTS FROM FORM CLASS");
	std::cout << YELLOW;
	std::cout << "Try to sign PaperWork with Trainee, it must work" << std::endl;
	std::cout << GREEN;
	try
	{
		PaperWork.beSigned(Trainee);
		std::cout << Trainee.getName() << " signed " << PaperWork.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << YELLOW;
	std::cout << "Try to re-sign PaperWork with Boss, it must not work" << std::endl;
	std::cout << RED;
	try
	{
		PaperWork.beSigned(Boss);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printSectionHeader("DESTRUCTORS");
	return (0);
}
