#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
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
	std::srand(std::time(NULL));
	printSectionHeader("CONSTRUCTORS");
	std::cout << GREEN;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	VP("VP", 50);
	Bureaucrat	Trainee("Trainee", 150);
	PresidentialPardonForm	DefaultPresidential;
	PresidentialPardonForm	Presidential("Presidential_target");
	RobotomyRequestForm		Robotomy("Robotomy_target");
	ShrubberyCreationForm	Shrubbery("Shrubbery_target");
	//AForm	test("test"); uncomment to see that AForm is an abstract class

	printSectionHeader("PRINT VARIABLES WITH '<<' OPERATOR");
	std::cout << YELLOW;
	std::cout << Boss << std::endl;
	std::cout << VP << std::endl;
	std::cout << Trainee << std::endl;
	std::cout << DefaultPresidential << std::endl;
	std::cout << Presidential << std::endl;
	std::cout << Robotomy << std::endl;
	std::cout << Shrubbery << std::endl;

	printSectionHeader("SIGNING FORMS");
	std::cout << CYAN;
	Trainee.signForm(Shrubbery);
	VP.signForm(Robotomy);
	VP.signForm(Shrubbery);
	VP.signForm(Presidential);
	Boss.signForm(Shrubbery);
	Boss.signForm(Presidential);

	printSectionHeader("EXECUTE FORMS");
	std::cout << MAGENTA;
	Trainee.executeForm(Shrubbery);
	VP.executeForm(Shrubbery);
	VP.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(DefaultPresidential);
	Boss.executeForm(Presidential);

	printSectionHeader("ROBOTOMY RAND TEST");
	std::cout << YELLOW;
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);
	Boss.executeForm(Robotomy);

	printSectionHeader("DESTRUCTORS");
	return (0);
}
