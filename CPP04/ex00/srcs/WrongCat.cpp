#include "../includes/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << this->_type << ": Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
: WrongAnimal(other)
{
	std::cout << this->_type << ": Copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << this->_type << ": Copy assigment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << this->_type << ": Destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << this->_type << ": *Meow Meow*" << std::endl;
}
