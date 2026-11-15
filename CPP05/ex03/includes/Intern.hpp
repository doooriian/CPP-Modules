#pragma once
#include "AForm.hpp"
#include <string>

class	Intern
{
	public:

		// Canonical Form
		Intern(void);
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern(void);

		// Form related function
		AForm	*makeForm(const std::string &name, const std::string &target) const;

	private:

		// Form related functions
		AForm		*makePresidential(const std::string &target) const;
		AForm		*makeRobotomy(const std::string &target) const;
		AForm		*makeShrubbery(const std::string &target) const;
};
