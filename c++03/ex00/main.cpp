#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	std::string	a("Sjonnie");
	std::string	b("Harry");
	ClapTrap	sjonnie(a);
	ClapTrap	harry(b);

	sjonnie.setAttack(5);
	for (int i = 0; i < 5; i++)
	{
		sjonnie.attack(b);
		harry.takeDamage(sjonnie.getAttack());
		harry.beRepaired(2);
	}
}