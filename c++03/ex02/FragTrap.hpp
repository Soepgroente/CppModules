#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	
	void highFivesGuys();
	FragTrap();
	FragTrap(std::string& name);
	FragTrap(const FragTrap& trap);
	void	operator=(const FragTrap& trap);
	~FragTrap();
};
