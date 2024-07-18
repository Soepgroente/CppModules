#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

	void	guardGate();
	void	attack(const std::string& target);

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& trap);
	~ScavTrap();

	void	operator=(const ScavTrap& trap);

	const static uint32_t defaultHP;
	const static uint32_t defaultEP;
	const static uint32_t defaultAD;
	const static std::string defaultName;
};
