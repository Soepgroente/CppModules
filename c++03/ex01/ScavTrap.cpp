#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	_name = "ScavTrap";
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

void	ScavTrap::operator=(const ScavTrap& trap)
{
	this->_name = trap._name;
	this->_hp = trap._hp;
	this->_ep = trap._ep;
	this->_ad = trap._ad;
	std::cout << "ScavTrap assignment operator called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << "is in gatekeeping mode" << std::endl;
}
