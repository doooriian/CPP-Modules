#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"
#include <iostream>
#include <iomanip>

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
	Animal	animal1;
	Cat		cat1;
	Cat 	cat2 = cat1;
	Dog		dog1;
	Dog		dog2;
	dog1 = dog2;
	std::cout << RESET;

	printSectionHeader("BASE POINTERS");
	std::cout << CYAN;
	const Animal	*animal = new Animal("Random Animal");
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
	std::cout << RESET;

	printSectionHeader("WRONG POINTERS");
	std::cout << RED;
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();
	std::cout << RESET;

	printSectionHeader("TYPE TEST");
	std::cout << GREEN;
	std::cout << "Animal type test: " << animal->getType() << std::endl;
	std::cout << "Dog type test: " << dog->getType() << std::endl;
	std::cout << "Cat type test: " << cat->getType() << std::endl;
	std::cout << "WrongAnimal type test: " << wrongAnimal->getType() << std::endl;
	std::cout << "WrongCat type test: " << wrongCat->getType() << std::endl;
	std::cout << RESET;

	printSectionHeader("SOUNDS TEST");
	std::cout << MAGENTA;
	std::cout << "Animal sound test: ";
	std::cout << RESET;
	animal->makeSound();
	std::cout << MAGENTA;
	std::cout << "Dog sound test: ";
	std::cout << RESET;
	dog->makeSound();
	std::cout << MAGENTA;
	std::cout << "Cat sound test: ";
	std::cout << RESET;
	cat->makeSound();
	std::cout << MAGENTA;
	std::cout << "WrongAnimal sound test: ";
	std::cout << RESET;
	wrongAnimal->makeSound();
	std::cout << MAGENTA;
	std::cout << "WrongCat sound test: ";
	std::cout << RESET;
	wrongCat->makeSound();

	printSectionHeader("BASE POINTERS DESTRUCTORS");
	std::cout << YELLOW;
	delete animal;
	delete dog;
	delete cat;
	std::cout << RESET;

	printSectionHeader("WRONG POINTERS DESTRUCTORS");
	std::cout << RED;
	delete wrongAnimal;
	delete wrongCat;
	std::cout << RESET;

	printSectionHeader("STACK DESTRUCTORS");
	return (0);
}

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	return (0);
// }
