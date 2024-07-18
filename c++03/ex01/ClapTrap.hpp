#pragma once

#include <iostream>

class ClapTrap
{
	public:
	
	void		attack(const std::string& target);
	void		takeDamage(uint32_t amount);
	void		beRepaired(uint32_t amount);
	void		setAttack(uint32_t amount);
	uint32_t	getAttack();

	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const std::string& name, uint32_t hp, uint32_t ep, uint32_t ad);
	ClapTrap(const ClapTrap& trap);
	void	operator=(const ClapTrap& trap);
	~ClapTrap();

	protected:
	
	std::string	name;
	uint32_t	hp;
	uint32_t	ep;
	uint32_t	ad;
};
