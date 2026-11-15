#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	PhoneBook 	phonebook;
	std::string	input;

	std::cout << BLUE << "Please write one of the following commands : ADD, SEARCH, EXIT." << RESET << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			phonebook.Add();
		else if (input == "SEARCH")
			phonebook.Search();
		else if (input == "EXIT")
		{
			std::cout << RED << "Exiting the phonebook..." << RESET << std::endl;
			return (0);
		}
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
		std::cout << BLUE << "Please write one of the following commands : ADD, SEARCH, EXIT." << RESET << std::endl;
	}
	return (0);
}
