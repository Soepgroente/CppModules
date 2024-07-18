#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

	void	guardGate();
	void	attack(const std::string& target);

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& trap);
	~ScavTrap();

	void	operator=(const ScavTrap& trap);
};
