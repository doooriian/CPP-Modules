#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contacts_count = -1;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

int PhoneBook::Add(void)
{
	if (this->_contacts_count >= Contacts_limit - 1)
	{
		for (int i = 0; i < Contacts_limit - 1; i++)
			this->_contacts[i] = this->_contacts[i + 1];
		this->_contacts[Contacts_limit - 1].FillContact();
	}
	else
	{
		this->_contacts_count++;
		this->_contacts[_contacts_count].FillContact();
	}
	return (1);
}

int	PhoneBook::_DisplayPhonebook(void) const
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i <= this->_contacts_count; i++)
	{
		std::cout << std::setw(10) << i;
		this->_contacts[i].DisplayContactRow();
	}
	return (1);
}

int	PhoneBook::Search(void) const
{
	int			index;
	std::string	input;

	this->_DisplayPhonebook();
	std::cout << MAGENTA << "Enter the index of the contact to display: " << RESET;
	while (std::getline(std::cin, input))
	{
		if (input == "HOME")
			return (1);
		std::istringstream iss(input);
		if (!(iss >> index) || index > this->_contacts_count || index < 0)
			std::cout << RED << "Error: please enter a valid index. Or type HOME to go back." << RESET << std::endl;
		else
			this->_contacts[index].DisplayContact();
		std::cout << MAGENTA << "Enter the index of the contact to display: " << RESET;
	}
	return (1);
}
