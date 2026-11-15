#pragma once
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class	WrongCat: public WrongAnimal
{
	public:

		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat	&operator=(const WrongCat &other);
		~WrongCat();

		void	makeSound() const;
		Brain	*getBrain() const;

	private:

		Brain	*_brain;
};
