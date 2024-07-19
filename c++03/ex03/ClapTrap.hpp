#pragma once

#include <iostream>

class ClapTrap
{
	public:
	
	void			attack(const std::string& target);
	void			takeDamage(uint32_t amount);
	void			beRepaired(uint32_t amount);
	void			setAttack(uint32_t amount);
	void			setName(const std::string& name);
	std::string&	getName();
	uint32_t		getAttack();

	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const std::string& name, uint32_t hp, uint32_t ep, uint32_t ad);
	ClapTrap(const ClapTrap& trap);
	~ClapTrap();

	void	operator=(const ClapTrap& trap);

	protected:

	std::string	name;
	uint32_t	hp;
	uint32_t	ep;
	uint32_t	ad;

	const static uint32_t		defaultHP;
	const static uint32_t		defaultEP;
	const static uint32_t		defaultAD;
	const static std::string	defaultName;
};
