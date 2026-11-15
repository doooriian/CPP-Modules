#include "Base.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

#define RESET	"\033[0m"
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
	std::srand(time(NULL));

	printSectionHeader("GENERATE INSTANCES");
	std::cout << GREEN;
	Base	*base1 = generate();
	Base	*base2 = generate();
	Base	*base3 = generate();

	printSectionHeader("FIND TYPES BY POINTERS");
	std::cout << YELLOW;
	identify(base1);
	identify(base2);
	identify(base3);

	printSectionHeader("FIND TYPES BY REFERENCES");
	std::cout << MAGENTA;
	identify(*base1);
	identify(*base2);
	identify(*base3);

	printSectionHeader("DESTRUCTORS");
	delete(base1);
	delete(base2);
	delete(base3);
}
