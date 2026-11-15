#pragma once
#include <string>
#include <stdexcept>

class	AForm;

class	Bureaucrat
{
	public:

		//Canonical Form
		Bureaucrat(void);
		Bureaucrat	(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		//Other constructors
		Bureaucrat(const std::string &name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string &name, int grade);

		//Getters
		std::string	getName(void) const;
		int			getGrade(void) const;

		//Increments or decrements the grade
		void	promote(void);
		void	demote(void);

		//Form related function
		void	signForm(AForm &AForm);
		void	executeForm(AForm const &form) const;

		//Exceptions
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};


	private:

		const std::string	_name;
		int					_grade;
	};

	//Operator overload "<<"
	std::ostream	&operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);
