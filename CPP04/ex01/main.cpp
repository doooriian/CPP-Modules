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
	printSectionHeader("SUBJECT TESTS");
	std::cout << MAGENTA;
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j;
	delete i;
	std::cout << RESET;

	printSectionHeader("BUILDING ARRAY OF ANIMALS");
	std::cout << YELLOW;
	const int	animals_nb = 10;
	Animal *animal_array[animals_nb];
	for (int i = 0; i < animals_nb; ++i)
	{
		if (i < animals_nb / 2)
			animal_array[i] = new Dog;
		else
			animal_array[i] = new Cat;
	}
	std::cout << RESET;

	printSectionHeader("ALL ANIMALS MAKE SOUND");
	std::cout << CYAN;
	for (int i = 0; i < animals_nb; ++i)
		animal_array[i]->makeSound();
	std::cout << RESET;

	printSectionHeader("DESTROYING THE ARRAY");
	std::cout << BLUE;
	for (int i = 0; i < animals_nb; ++i)
		delete (animal_array[i]);
	std::cout << RESET;

	printSectionHeader("BRAIN TESTS");
	std::cout << GREEN;
	Dog	dog1;
	Dog	dog2;

	dog1.getBrain()->setIdea(0, "eat");
	dog1.getBrain()->setIdea(1, "sleep");
	dog1.getBrain()->setIdea(2, "repeat");

	dog2 = dog1;
	dog2.getBrain()->setIdea(0, "woof");
	dog2.getBrain()->setIdea(1, "woof woof");
	dog2.getBrain()->setIdea(2, "woof woof woof");

	std::cout << "d1 ideas: ["
	<< dog1.getBrain()->getIdea(0) << "], ["
	<< dog1.getBrain()->getIdea(1) << "], ["
	<< dog1.getBrain()->getIdea(2) << "]" << std::endl;

	std::cout << "d2 ideas: ["
	<< dog2.getBrain()->getIdea(0) << "], ["
	<< dog2.getBrain()->getIdea(1) << "], ["
	<< dog2.getBrain()->getIdea(2) << "]" << std::endl;

	std::cout << "Brain ptrs (must differ): d1=" << dog1.getBrain()
	<< " d2=" << dog2.getBrain() << std::endl;
	std::cout << RESET;

	printSectionHeader("WRONG INDEX");
	std::cout << MAGENTA;
	dog1.getBrain()->setIdea(100, "wrong index");
	std::cout << dog1.getBrain()->getIdea(100);
	std::cout << RESET;

	printSectionHeader("DESTRUCTOR");

	return (0);
}

// int main()
//{
//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//	delete j;//should not create a leak
//	delete i;
//
//	return (0);
//}
