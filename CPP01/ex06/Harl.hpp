#pragma once
#include <string>

class	Harl
{
	public:

		Harl(void);
		~Harl(void);
		void	complain(std::string level);

	private:

		void	debug();
		void	info();
		void	warning();
		void	error();

};