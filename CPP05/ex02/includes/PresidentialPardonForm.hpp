#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		//Canonical Form
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		// Constructor by target
		PresidentialPardonForm(const std::string &target);

		//Execute related function
		void	executeAction(void) const;

	private:

		std::string	_target;
};
