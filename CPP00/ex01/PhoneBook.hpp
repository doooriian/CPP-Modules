#pragma once
#include "Contact.hpp"
#define Contacts_limit 8

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int	Add(void);
		int	Search(void) const;
		
		private:
		int		_contacts_count;
		Contact	_contacts[Contacts_limit];
		int		_DisplayPhonebook(void) const;
};