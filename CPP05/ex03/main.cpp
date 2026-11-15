#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Intern.hpp"
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
	printSectionHeader("CONSTRUCTORS AND COPY");
	std::cout << GREEN;
	Intern	Intern1;
	Intern	Intern2;
	Intern1 = Intern2;

	printSectionHeader("CREATING GOOD FORMS");
	std::cout << YELLOW;
	AForm *form1 = Intern1.makeForm("presidential pardon", "presidential_target");
	AForm *form2 = Intern1.makeForm("robotomy request", "robotomy_target");
	AForm *form3 = Intern1.makeForm("shrubbery creation", "shrubbery_target");

	printSectionHeader("CREATING BAD FORMS");
	std::cout << CYAN;
	Intern1.makeForm("presidential", "presidential_target");
	Intern1.makeForm("unknown form", "unknown_target");

	printSectionHeader("DESTRUCTORS");
	delete form1;
	delete form2;
	delete form3;
	return (0);
}
