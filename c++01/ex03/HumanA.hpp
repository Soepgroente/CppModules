#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:

	Weapon&		_weapon;
	std::string	_name;
	
	public:

	void	attack();
	HumanA() = delete;
	HumanA(Weapon& weapon, std::string name);
	~HumanA();
};

#endif