#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
: ClapTrap("Random")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuardMode = false;
	
	std::cout << "ScavTrap " << this->_name << ": Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuardMode = false;

	std::cout << "ScavTrap " << this->_name << ": Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other)
{
	this->_isGuardMode = other._isGuardMode;
	std::cout << "ScavTrap " << this->_name << ": Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap " << this->_name << ": Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_isGuardMode = other._isGuardMode;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << ": Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	this->_isGuardMode = !this->_isGuardMode;

	if (this->_isGuardMode)
		std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " has stopped guarding the gate!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
		std::cout << "ScavTrap " << this->_name << " is dead..." << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "ScavTrap " << this->_name << " has no more energy..." << std::endl;
	else
	{	
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	}
}