#pragma once

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

	void	attack(const std::string& target);
	void	whoAmI();
	
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& trap);
	~DiamondTrap();

	void	operator=(const DiamondTrap& trap);

	private:

	std::string	Name;
	std::string	ClapTrapName;
	uint32_t	hp;
	uint32_t	ep;
	uint32_t	ad;

	const static uint32_t defaultHP;
	const static uint32_t defaultEP;
	const static uint32_t defaultAD;
	const static std::string defaultName;
};
