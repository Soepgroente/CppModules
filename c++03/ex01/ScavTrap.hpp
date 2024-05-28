#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		void guardGate();
		ScavTrap();
		ScavTrap(std::string& name);
		~ScavTrap();
};
