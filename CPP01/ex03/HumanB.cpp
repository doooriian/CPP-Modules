#include "HumanB.hpp"
#include "iostream"

HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (this->_weapon == NULL)
		std::cout << this->_name << "attacks with their own hand" << std::endl;
	std::cout << this->_name << " attacks with their "
	<< this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_weapon = &Weapon;
}
