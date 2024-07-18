#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	
	void	highFivesGuys();
	void	attack(const std::string& target);
	
	FragTrap();
	FragTrap(std::string& name);
	FragTrap(const FragTrap& trap);
	~FragTrap();

	void	operator=(const FragTrap& trap);
};
