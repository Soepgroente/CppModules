#include "Weapon.hpp"

const std::string&	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

Weapon::Weapon()
{
}

Weapon::Weapon(std::string name)
{
	this->type = name;
}

Weapon::~Weapon()
{
}