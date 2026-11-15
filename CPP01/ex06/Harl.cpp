#include "Harl.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE  "\033[38;5;208m"
#define RED     "\033[31m"

Harl::Harl()
{
	std::cout << "Harl enters the restaurant." << std::endl;
}

Harl::~Harl()
{
	std::cout << std::endl << "Harl leaves the restaurant." << std::endl;
}

void	Harl::complain(std::string level)
{
	int			index = -1;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*ptr[])() = {&Harl::debug, &Harl::info, \
				&Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			(this->*ptr[0])();
		case 1:
			(this->*ptr[1])();
		case 2:
			(this->*ptr[2])();
		case 3:
			(this->*ptr[3])();
			break;
		default:
			std::cout << std::endl << "[ Probably complaining about"
			" insignificant problems ]" << std::endl;
	}
}

void	Harl::debug()
{
	std::cout << std::endl << GREEN << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< std::endl << "I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout <<std::endl << YELLOW << "[ INFO ]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
	"You didn’t put enough bacon in my burger!" << std::endl <<
	"If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << std::endl << ORANGE << "[ WARNING ]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
	<<std::endl << "I’ve been coming for years, whereas you started working"
	"here just last month." << std::endl;
}

void	Harl::error()
{
	std::cout << std::endl << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}
