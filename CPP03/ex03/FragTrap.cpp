#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
: ClapTrap("Anonymous")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	
	std::cout << "FragTrap " << this->_name << ": Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name)
: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap " << this->_name << ": Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
: ClapTrap(other)
{
	std::cout << "FragTrap " << this->_name << ": Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap " << this->_name << ": Copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << ": Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << this->_name << " says: \"Come on let's"
	" do an high five guys!\"" << std::endl;
}