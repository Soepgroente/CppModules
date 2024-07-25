#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

	void	guardGate();

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& trap);
	~ScavTrap();

	void	operator=(const ScavTrap& trap);
};
