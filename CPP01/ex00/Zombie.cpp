#include "Zombie.hpp"
#include "iostream"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been deleted" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl;
}
