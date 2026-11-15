#include "iostream"
#include "string"


#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << CYAN << "String address:          " << RESET << &string << std::endl;
    std::cout << CYAN << "stringPTR address:       " << RESET << stringPTR << std::endl;
    std::cout << CYAN << "stringREF address:       " << RESET << &stringREF << std::endl;

    std::cout << GREEN << "String value:            " << RESET << string << std::endl;
    std::cout << GREEN << "Value pointed by PTR:    " << RESET << *stringPTR << std::endl;
    std::cout << GREEN << "Value referenced by REF: " << RESET << stringREF << std::endl;
}