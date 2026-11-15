#pragma once
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack() const;
		void	setWeapon(Weapon &Weapon);

	private:
		std::string _name;
		Weapon		*_weapon;
};