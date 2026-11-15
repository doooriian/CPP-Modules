#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat()
: Animal("Cat")
{
	this->_brain = new Brain;
	std::cout << this->_type << ": Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
: Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << this->_type << ": Copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	std::cout << this->_type << ": Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << this->_type << ": Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << this->_type << ": *Meow Meow*" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (_brain);
}
