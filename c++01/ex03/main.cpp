#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon	club = Weapon("crude spiked club");
	Weapon	napkin = Weapon("fragile piece of paper");
	HumanA	bob(club, "Bob");
	HumanB	jim("Jim");
	HumanB	Arnold("Arnold");

	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	club.setType("");
	jim.setWeapon(napkin);
	jim.attack();
	napkin.setType("sharp A4-paper");
	jim.attack();
	Arnold.attack();

	return (0);
}
