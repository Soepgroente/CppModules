#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hp = 100;
	ep = 50;
	ad = 20;
	name = "ScavTrap";
	type = "ScavTrap";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	hp = 100;
	ep = 50;
	ad = 20;
	type = "ScavTrap";
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
	this->type = trap.type;
	this->hp = trap.hp;
	this->ep = trap.ep;
	this->ad = trap.ad;
	std::cout << "ScavTrap assignment operator called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is in gatekeeping mode" << std::endl;
}
