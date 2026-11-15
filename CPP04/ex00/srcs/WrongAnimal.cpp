#include "../includes/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
: _type("WrongAnimal")
{
	std::cout << this->_type << ": Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
: _type(type)
{
		std::cout << this->_type << ": Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
: _type(other._type)
{
	std::cout << this->_type << ": Copy constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << this->_type << ": Copy assigment operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->_type << ": Destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->_type << ": *Unknown sound*" << std::endl;
}
