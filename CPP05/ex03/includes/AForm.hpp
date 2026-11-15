#pragma once
#include <string>
#include <stdexcept>

class	Bureaucrat;

class	AForm
{
	public:

		//Canonical Form
		AForm(void);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm(void);

		//Other constructors
		AForm(const std::string &name);
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);

		//Getters
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		//Bureaucrat related function
		void			beSigned(const Bureaucrat &Bureaucrat);
		void			execute(const Bureaucrat &executor) const;
		virtual void	executeAction(void) const = 0;

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
		class	NotSignedException: public std::exception
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

std::ostream	&operator<<(std::ostream &out, const AForm &Form);
