#include "FragTrap.hpp"

const uint32_t		FragTrap::defaultHP = 100;
const uint32_t		FragTrap::defaultEP = 100;
const uint32_t		FragTrap::defaultAD = 30;
const std::string 	FragTrap::defaultName = "FragTrap";

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	hp = 100;
	ep = 100;
	ad = 30;
	name = "FragTrap";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& trap)
{
	*this = trap;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

void	FragTrap::operator=(const FragTrap& trap)
{
	this->name = trap.name;
	this->hp = trap.hp;
	this->ep = trap.ep;
	this->ad = trap.ad;
	std::cout << "FragTrap assignment operator called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << "is SHOUTING for some high fives!!!!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hp == 0)
	{
		std::cout << "FragTrap " << this->name << " is dead and cannot attack" << std::endl;
	}
	else if (ep > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target \
			<< " causing " << this->ad << " points of damage!" << std::endl;
		ep--;
	}
	else
		std::cout << "FragTrap " << this->name << \
			" has insufficient energy points to attack" << std::endl;
}