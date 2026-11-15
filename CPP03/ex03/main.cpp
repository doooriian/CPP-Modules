#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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

	printSectionHeader("FRAGTRAP CONSTRUCTORS AND COPIES");
	std::cout << YELLOW;
	FragTrap f1;
	FragTrap f2("FlopTrap");
	FragTrap f3 = f2;
	std::cout << RESET;

	printSectionHeader("DIAMONDTRAP CONSTRUCTORS AND COPIES");
	std::cout << YELLOW;
	DiamondTrap d1;
	DiamondTrap d2("Shiny");
	DiamondTrap d3 = d2;
	std::cout << RESET;

	printSectionHeader("ATTACKS");
	std::cout << RED;
	a.attack("John");
	b.attack("somebody else");
	s1.attack("an enemy");
	s2.attack("another enemy");
	f1.attack("you");
	f2.attack("a bush");
	d1.attack("a stone");
	d2.attack("the pc");
	std::cout << RESET;

	printSectionHeader("DAMAGES");
	std::cout << CYAN;
	a.takeDamage(3);
	c.takeDamage(8);
	s1.takeDamage(12);
	s3.takeDamage(20);
	f1.takeDamage(50);
	f3.takeDamage(150);
	d1.takeDamage(40);
	d3.takeDamage(60);
	std::cout << RESET;

	printSectionHeader("REPAIRED");
	std::cout << GREEN;
	a.beRepaired(5);
	c.beRepaired(10);
	s1.beRepaired(15);
	s3.beRepaired(10);
	f1.beRepaired(50);
	f3.beRepaired(1);
	d1.beRepaired(20);
	d2.beRepaired(30);
	std::cout << RESET;

	printSectionHeader("ENERGY");
	std::cout << MAGENTA;
	for (int i = 0; i < 11; i++)
		a.attack("the wind");
	a.beRepaired(10);
	for (int i = 0; i < 5; i++)
		s1.attack("the air");
	s1.beRepaired(5);
	for (int i = 0; i < 5; i++)
		f1.attack("the ground");
	f1.beRepaired(2);
	for (int i = 0; i < 5; i++) d1.attack("the clouds");
		d1.beRepaired(3);
	std::cout << RESET;

	printSectionHeader("GUARD MODE");
	std::cout << GREEN;
	s2.guardGate();
	s2.guardGate();
	s3.guardGate();
	d1.guardGate();
	d1.guardGate();
	std::cout << RESET;

	printSectionHeader("HIGH FIVES");
	std::cout << GREEN;
	f1.highFivesGuys();
	f2.highFivesGuys();
	f3.highFivesGuys();
	d2.highFivesGuys();
	d2.highFivesGuys();
	std::cout << RESET;

	printSectionHeader("DIAMONDTRAP WHOAMI");
	std::cout << CYAN;
	d1.whoAmI();
	d2.whoAmI();
	d3.whoAmI();
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
	d2.takeDamage(200);
	d2.attack("Nobody");
	std::cout << RESET;

	printSectionHeader("DESTRUCTORS");
	return (0);
}
