#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

ClapTrap::ClapTrap()
: _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << ": Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << ": Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
: _name(other._name), _hitPoints(other._hitPoints),
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << this->_name << ": Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << this->_name << ": Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << ": Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " is dead..." << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "ClapTrap " << this->_name << " has no more energy..." << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > INT_MAX)
		amount = INT_MAX;
	if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " is already dead..." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points"
		" of damage!";
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
		{
			if (this->_hitPoints < 0)
				this->_hitPoints = 0;
			std::cout << " He died from his injuries..." << std::endl;
		}
		else
			std::cout << " He now has: " << this->_hitPoints << "HP" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (amount > INT_MAX)
		amount = INT_MAX;
	if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " is dead..." << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "ClapTrap " << this->_name << " has no more energy..." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " regains " << amount << " points"
		" of hit points!";
		if (this->_hitPoints >= INT_MAX - amount)
			this->_hitPoints = INT_MAX;
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << " He now has: " << this->_hitPoints << "HP" << std::endl;
	}
}
