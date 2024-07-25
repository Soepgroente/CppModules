#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	std::string	a("Thing");
	std::string	b("Monster");
	std::string	c("SJON");
	ClapTrap	Sjon(c);
	ScavTrap	Barbed(a);
	ScavTrap	Wire(b);
	ScavTrap	Random;

	Wire.setAttack(2);
	Random.attack(c);
	Random.guardGate();
	for (int i = 0; i < 6; i++)
	{
		Barbed.attack(b);
		Wire.beRepaired(2);
		Wire.takeDamage(Barbed.getAttack());
	}
}