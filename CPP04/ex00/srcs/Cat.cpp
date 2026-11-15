#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat()
: Animal("Cat")
{
	std::cout << this->_type << ": Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
: Animal(other)
{
	std::cout << this->_type << ": Copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << this->_type << ": Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << this->_type << ": Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << this->_type << ": *Meow Meow*" << std::endl;
}
