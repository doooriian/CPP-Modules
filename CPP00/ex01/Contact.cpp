#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	// std::cout << "Contact has been destroyed" << std::endl;
	return;
}

int	Contact::DisplayContact(void) const
{
	std::cout << std::endl << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl << std::endl;
	return (1);
}

int	Contact::DisplayContactRow(void) const
{
	if (this->_first_name.length() > 10)
		std::cout << '|' << this->_first_name.substr(0, 9) << ".";
	else
		std::cout << '|' << std::setw(10) << this->_first_name;
	if (this->_last_name.length() > 10)
		std::cout << '|' << this->_last_name.substr(0, 9) << ".";
	else
		std::cout << '|' << std::setw(10) << this->_last_name;
	if (this->_nickname.length() > 10)
		std::cout << '|' << this->_nickname.substr(0, 9) << ".";
	else
		std::cout << '|' << std::setw(10) << this->_nickname;
	std::cout << std::endl;
	return (1);
}

int	Contact::FillContact(void)
{
	std::cout << MAGENTA << "Please fill the following informations" << RESET << std::endl;

	std::cout << "First name: ";
	std::getline(std::cin, this->_first_name);
	while (this->_first_name.empty())
	{
		std::cout << RED << "First name cannot be empty. Please try again: " << RESET;
		std::getline(std::cin, this->_first_name);
	}

	std::cout << "Last name: ";
	std::getline(std::cin, this->_last_name);
	while (this->_last_name.empty())
	{
		std::cout << RED << "Last name cannot be empty. Please try again: " << RESET;
		std::getline(std::cin, this->_last_name);
	}

	std::cout << "Nickname: ";
	std::getline(std::cin, this->_nickname);
	while (this->_nickname.empty())
	{
		std::cout << RED << "Nickname cannot be empty. Please try again: " << RESET;
		std::getline(std::cin, this->_nickname);
	}

	std::cout << "Phone number: ";
	std::getline(std::cin, this->_phone_number);
	while (this->_phone_number.empty())
	{
		std::cout << RED << "Phone number cannot be empty. Please try again: " << RESET;
		std::getline(std::cin, this->_phone_number);
	}

	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->_darkest_secret);
	while (this->_darkest_secret.empty())
	{
		std::cout << RED << "Darkest secret cannot be empty. Please try again: " << RESET;
		std::getline(std::cin, this->_darkest_secret);
	}
	return (1);
}
