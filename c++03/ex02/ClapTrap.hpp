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

	public:
		ClapTrap();
		ClapTrap(std::string& name);
		ClapTrap(std::string& name, uint32_t hp, uint32_t ep, uint32_t ad);
		~ClapTrap();

	protected:
		std::string	_name;
		uint32_t	_hp;
		uint32_t	_ep;
		uint32_t	_ad;
};
