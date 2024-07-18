#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	
	void	highFivesGuys();
	void	attack(const std::string& target);
	
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& trap);
	~FragTrap();

	void	operator=(const FragTrap& trap);

	const static uint32_t defaultHP;
	const static uint32_t defaultEP;
	const static uint32_t defaultAD;
	const static std::string defaultName;
};
