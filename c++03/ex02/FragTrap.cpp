#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	hp = 100;
	ep = 100;
	ad = 30;
	name = "FragTrap";
	type = "FragTrap";
}

FragTrap::FragTrap(std::string& name) : ClapTrap(name)
{
	hp = 100;
	ep = 100;
	ad = 30;
	type = "FragTrap";
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
	this->type = trap.type;
	this->hp = trap.hp;
	this->ep = trap.ep;
	this->ad = trap.ad;
	std::cout << "FragTrap assignment operator called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " is SHOUTING for some high fives!!!!" << std::endl;
}
