#include "DiamondTrap.hpp"

const uint32_t		DiamondTrap::defaultHP = FragTrap::defaultHP;
const uint32_t		DiamondTrap::defaultEP = ScavTrap::defaultEP;
const uint32_t		DiamondTrap::defaultAD = FragTrap::defaultAD;
const std::string	DiamondTrap::defaultName = "DiamondTrap";

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	hp = DiamondTrap::defaultHP;
	ep = DiamondTrap::defaultEP;
	ad = DiamondTrap::defaultAD;
	Name = DiamondTrap::defaultName;
	ClapTrapName = ClapTrap::name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string& name) : ClapTrap(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	hp = defaultHP;
	ep = defaultEP;
	ad = defaultAD;
	Name = name;
	ClapTrapName = ClapTrap::name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap)
{
	*this = trap;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::operator=(const DiamondTrap& trap)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	this->Name = trap.Name;
	this->ClapTrapName = trap.ClapTrapName;
	this->hp = trap.hp;
	this->ep = trap.ep;
	this->ad = trap.ad;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Am I " << this->Name << " or " << this->ClapTrapName << "??? I don't know anymore... :-(" << std::endl;
}