#pragma once
#include "string"

class	Zombie
{
	public:

		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce();
		void	setName(std::string name);

	private:

		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);
