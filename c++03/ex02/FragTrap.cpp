#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	_name = "FragTrap";
}

FragTrap::FragTrap(std::string& name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << "is SHOUTING for some high fives!!!!" << std::endl;
}
