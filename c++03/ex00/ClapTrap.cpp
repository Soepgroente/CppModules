#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hp(10), ep(10), ad(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : hp(10), ep(10), ad(0)
{
	this->name = name;
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& trap)
{
	*this = trap;
	std::cout << "Copy constructor called" << std::endl;
}

void	ClapTrap::operator=(const ClapTrap& trap)
{
	if (this == &trap)
		return ;
	this->name = trap.name;
	this->hp = trap.hp;
	this->ep = trap.ep;
	this->ad = trap.ad;
	std::cout << "Assignment operator called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor called" << std::endl;
}

void	ClapTrap::setAttack(uint32_t amount)
{
	this->ad = amount;
	std::cout << this->name << "\'s attack has been set to " << amount << std::endl;
}

uint32_t	ClapTrap::getAttack(void)
{
	return (this->ad);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hp == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack" << std::endl;
	}
	else if (ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target \
			<< " causing " << this->ad << " points of damage!" << std::endl;
		ep--;
	}
	else
		std::cout << "ClapTrap " << this->name << \
			" has insufficient energy points to attack" << std::endl;
}

void	ClapTrap::takeDamage(uint32_t amount)
{
	if (hp > 0)
	{
		std::cout << "ClapTrap " << this->name << " takes " << amount \
			<< " points of damage!" << std::endl;
		if (amount >= hp)
			hp = 0;
		else
			hp -= amount;
	}
	if (hp == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(uint32_t amount)
{
	if (hp == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and cannot be repaired" << std::endl;
	}
	else if (ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount \
			<< " hit points" << std::endl;
		ep--;
		hp += amount;
	}
	else
		std::cout << "ClapTrap " << this->name << \
			" has insufficient energy points to repair itself" << std::endl;
}