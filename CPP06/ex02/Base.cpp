#include "Base.hpp"
#include <iostream>

#define RED		"\033[31m"
#define RESET	"\033[0m"

Base::~Base()
{
	std::cout << RED << "Base default destructor called" << RESET << std::endl;
}

Base	*generate()
{
	int randNum = rand() % 3;

	std::cout << "rand: " << randNum << std::endl;
	switch (randNum)
	{
		case 0:
		{
			std::cout << "A type generated" << std::endl;
			return (new A);
		}
		case 1:
		{
			std::cout << "B type generated" << std::endl;
			return (new B);
		}
		case 2:
		{
			std::cout << "C type generated" << std::endl;
			return (new C);
		}
		default:
		{
			std::cout << "Error while generating" << std::endl;
			return (NULL);
		}
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A type detected" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B type detected" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C type detected" << std::endl;
	else
		std::cout << "Error: type not detected" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A type detected" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B type detected" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C type detected" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	std::cout << "Error: type not detected" << std::endl;
}
