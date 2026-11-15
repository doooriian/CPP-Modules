#include "Serializer.hpp"
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

void	printData(const Data &data)
{
	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Data id: " << data.id << std::endl;
	std::cout << "Data name: " << data.name << std::endl;
	std::cout << "Data value: " << data.value << std::endl;
}

int	main(void)
{
	printSectionHeader("DATA CREATION");
	std::cout << GREEN;
	Data	data;
	data.id = 42;
	data.name = "Dorian";
	data.value = 14.149;
	printData(data);

	printSectionHeader("SERIALIZATION TEST");
	std::cout << YELLOW;
	uintptr_t	raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t value: " << raw << std::endl;

	printSectionHeader("DESERIALIZATION TEST");
	std::cout << MAGENTA;
	Data	*ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized ptr value: " << ptr << std::endl;

	printSectionHeader("PRINTING DATA THROUGH PTR");
	std::cout << CYAN;
	printData(*ptr);
	std::cout << RESET;
	return (0);
}
