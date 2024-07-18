#include <iostream>
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	ConfusedOne;
	ClapTrap	Sjon(std::string("SJON"));
	FragTrap	Happy(std::string("Happy"));
	FragTrap	Clown;
	FragTrap	Random;

	Clown.setName("Clown");
	Clown.setAttack(2);
	Random.attack(Clown.getName());
	for (int i = 0; i < 2; i++)
	{
		Happy.attack(Clown.getName());
		Clown.takeDamage(Happy.getAttack());
		Clown.beRepaired(2);
		Random.highFivesGuys();
		ConfusedOne.whoAmI();
		ConfusedOne.attack(Happy.getName());
		ConfusedOne.takeDamage(1);
		ConfusedOne.beRepaired(1);
		ConfusedOne.highFivesGuys();
	}
}