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

ScavTrap::ScavTrap(std::string& name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScapTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScapTrap " << this->_name << "is in gatekeeping mode" << std::endl;
}
