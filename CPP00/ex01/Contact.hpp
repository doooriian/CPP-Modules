#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#define RESET "\x1b[0m"
#define BLUE "\x1b[34m"
#define RED "\x1b[31m"
#define MAGENTA "\x1b[35m"

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		int DisplayContact(void) const;
		int	DisplayContactRow(void) const;
		int	FillContact(void);

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};