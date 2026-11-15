#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:

		//Canonical Form
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		// Constructor by target
		ShrubberyCreationForm(const std::string &target);

		//Execute related function
		void	executeAction(void) const;

	private:

		std::string	_target;
};
