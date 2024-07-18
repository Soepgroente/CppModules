#include "ScavTrap.hpp"

const uint32_t		ScavTrap::defaultHP = 100;
const uint32_t		ScavTrap::defaultEP = 100;
const uint32_t		ScavTrap::defaultAD = 30;
const std::string	ScavTrap::defaultName = "ScavTrap";

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hp = 100;
	ep = 50;
	ad = 20;
	name = "ScavTrap";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& trap)
{
	*this = trap;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::operator=(const ScavTrap& trap)
{
	this->name = trap.name;
	this->hp = trap.hp;
	this->ep = trap.ep;
	this->ad = trap.ad;
	std::cout << "ScavTrap assignment operator called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << "is in gatekeeping mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hp == 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead and cannot attack" << std::endl;
	}
	else if (ep > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target \
			<< " causing " << this->ad << " points of damage!" << std::endl;
		ep--;
	}
	else
		std::cout << "ScavTrap " << this->name << \
			" has insufficient energy points to attack" << std::endl;
}