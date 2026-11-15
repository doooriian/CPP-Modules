#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		//Canonical Form
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		// Constructor by target
		RobotomyRequestForm(const std::string &target);

		//Execute related function
		void	executeAction(void) const;

	private:

		std::string	_target;
};
