#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

void	HumanB::attack()
{
	if (_weapon == nullptr)
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = nullptr;
}

HumanB::HumanB() : _name("")
{
}

HumanB::~HumanB()
{
}
