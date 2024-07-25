#include <iostream>
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	ConfusedOne;
	DiamondTrap	Diamond("Diamond");

	ConfusedOne.whoAmI();
	Diamond.whoAmI();
	for (int i = 0; i < 2; i++)
	{
		Diamond.beRepaired(2);
		ConfusedOne.attack(Diamond.getName());
		ConfusedOne.takeDamage(1);
		ConfusedOne.beRepaired(1);
		ConfusedOne.highFivesGuys();
	}
}