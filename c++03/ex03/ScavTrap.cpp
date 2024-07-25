#include "ScavTrap.hpp"

const uint32_t		ScavTrap::defaultHP = 100;
const uint32_t		ScavTrap::defaultEP = 100;
const uint32_t		ScavTrap::defaultAD = 30;
const std::string	ScavTrap::defaultName = "ScavTrap";

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hp = defaultHP;
	ep = defaultEP;
	ad = defaultAD;
	name = defaultName;
	type = "ScavTrap";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap()
{
	hp = defaultHP;
	ep = defaultEP;
	ad = defaultAD;
	this->name = name;
	type = "ScavTrap";
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
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this == &trap)
		return ;
	this->name = trap.name;
	this->type = trap.type;
	this->hp = trap.hp;
	this->ep = trap.ep;
	this->ad = trap.ad;
}

void	ScavTrap::guardGate()
{
	std::cout << this->type << " " << this->name << " is in gatekeeping mode" << std::endl;
}
