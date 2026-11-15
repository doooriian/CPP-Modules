#pragma once
#include <string>
#include <stdexcept>

class	Bureaucrat;

class	Form
{
	public:

		//Canonical Form
		Form(void);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form(void);

		//Other constructors
		Form(const std::string &name);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		//Getters
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		//Bureaucrat related function
		void	beSigned(const Bureaucrat &Bureaucrat);

		//Exceptions
		class	GradeTooHighException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	AlreadySignedException: public std::exception
		{
			public:
				const char	*what() const throw();
		};

	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &out, const Form &Form);
