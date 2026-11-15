#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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

void printSectionHeader(const std::string& title)
{
	std::cout << std::endl << BOLD << BLUE << "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE << "║ " << std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
	std::cout << BOLD << BLUE << "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
}

int main(void)
{
	printSectionHeader("CLAPTRAP CONSTRUCTORS AND COPIES");
	std::cout << YELLOW;
	ClapTrap a;
	ClapTrap b("John");
	ClapTrap c = b;
	std::cout << RESET;

	printSectionHeader("SCAVTRAP CONSTRUCTORS AND COPIES");
	std::cout << YELLOW;
	ScavTrap s1;
	ScavTrap s2("Guardian");
	ScavTrap s3 = s2;
	std::cout << RESET;

	printSectionHeader("ATTACKS");
	std::cout << RED;
	a.attack("John");
	b.attack("somebody else");
	s1.attack("an enemy");
	s2.attack("another enemy");
	std::cout << RESET;

	printSectionHeader("DAMAGES");
	std::cout << CYAN;
	a.takeDamage(3);
	c.takeDamage(8);
	s1.takeDamage(12);
	s3.takeDamage(20);
	std::cout << RESET;

	printSectionHeader("REPAIRED");
	std::cout << GREEN;
	a.beRepaired(5);
	c.beRepaired(10);
	s1.beRepaired(15);
	s3.beRepaired(10);
	std::cout << RESET;

	printSectionHeader("ENERGY");
	std::cout << MAGENTA;
	for (int i = 0; i < 11; i++)
		a.attack("the wind");
	a.beRepaired(10);
	for (int i = 0; i < 5; i++)
		s1.attack("the air");
	s1.beRepaired(5);
	std::cout << RESET;

	printSectionHeader("GUARD MODE");
	std::cout << GREEN;
	s2.guardGate();
	s2.guardGate();
	s3.guardGate();
	std::cout << RESET;

	printSectionHeader("DEATH AND OVERFLOWS");
	std::cout << YELLOW;
	b.beRepaired(UINT_MAX);
	b.beRepaired(UINT_MAX);
	b.takeDamage(UINT_MAX);
	b.takeDamage(10);
	b.attack("You");
	b.beRepaired(10);
	s1.takeDamage(200);
	s1.attack("Ghost");
	std::cout << RESET;

	printSectionHeader("DESTRUCTORS");
	return (0);
}
