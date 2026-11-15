#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>
#include <climits>

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
	printSectionHeader("CONSTRUCTORS AND COPIES");
	std::cout << YELLOW;
	ClapTrap	a;
	ClapTrap	b("John");
	ClapTrap	c = b;
	std::cout << RESET;

	printSectionHeader("ATTACKS");
	std::cout << RED;
	a.attack("John");
	b.attack("somebody else");
	std::cout << RESET;

	printSectionHeader("DAMAGES");
	std::cout << CYAN;
	a.takeDamage(3);
	c.takeDamage(8);

	printSectionHeader("REPAIRED");
	std::cout << GREEN;
	a.beRepaired(5);
	c.beRepaired(10);
	std::cout << RESET;

	printSectionHeader("ENERGY");
	std::cout << MAGENTA;
	for (int i = 0; i < 11; i++)
		a.attack("the wind");
	a.beRepaired(10);
	std::cout << RESET;

	printSectionHeader("DEATH AND OVERFLOWS");
	std::cout << YELLOW;
	b.beRepaired(UINT_MAX);
	b.beRepaired(UINT_MAX);
	b.takeDamage(UINT_MAX);
	b.takeDamage(10);
	b.attack("You");
	b.beRepaired(10);
	std::cout << RESET;

	printSectionHeader("DESTRCUTORS");
	return (0);
}
