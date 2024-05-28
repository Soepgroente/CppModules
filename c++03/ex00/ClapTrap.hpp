#pragma once

#include <iostream>

/*	Include copy constructor && assignment operator overload	*/

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
	~ClapTrap();

	private:
		std::string	name;
		uint32_t	hp;
		uint32_t	ep;
		uint32_t	ad;
};
