#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	std::string	a("Thing");
	std::string	b("Monster");
	std::string	c("SJON");
	ClapTrap	Sjon(c);
	FragTrap	Happy(a);
	FragTrap	Clown(b);
	FragTrap	Random;

	Clown.setAttack(2);
	Random.attack(c);
	for (int i = 0; i < 2; i++)
	{
		Happy.attack(b);
		Clown.beRepaired(2);
		Clown.takeDamage(Happy.getAttack());
		Random.highFivesGuys();
	}
}