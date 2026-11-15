#include <iostream>
#include "Zombie.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

int main(void)
{
    std::cout << std::endl << CYAN << "Creating a zombie on the stack..." << RESET << std::endl;
    Zombie stackZombie("Stacky");
    stackZombie.announce();

    std::cout << GREEN << "\nCreating a zombie on the heap..." << RESET << std::endl;
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();

    std::cout << YELLOW << "\nCalling randomChump (stack allocation inside the function)..." << RESET << std::endl;
    randomChump("Chumpy");

    std::cout << RED << "\nDeleting the heap zombie..." << RESET << std::endl;
    delete heapZombie;

    std::cout << CYAN << "\nEnd of main, stack zombies will be destroyed automatically." << RESET << std::endl;

    return (0);
}
