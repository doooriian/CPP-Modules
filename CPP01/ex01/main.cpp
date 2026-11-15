#include "Zombie.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

int main(void)
{
    int N = 5;
    std::string baseName = "Zombie";

    std::cout << CYAN << "Creating a horde of " << N << " zombies named '" << baseName << "'..." << RESET << std::endl;

    Zombie* horde = zombieHorde(N, baseName);

    std::cout << GREEN << "\nEach zombie announces itself:" << RESET << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << RED << "[" << i + 1 << "] " << RESET;
        horde[i].announce();
    }

    std::cout << CYAN << "\nCleaning up the horde..." << RESET << std::endl;
    delete[] horde;

    std::cout << GREEN << "All zombies have been deleted." << RESET << std::endl;

    return (0);
}
