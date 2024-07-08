#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _hp(10), _ep(10), _ad(0)
{
	this->_name = name;
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, uint32_t hp, uint32_t ep, uint32_t ad) :
	_name(name), _hp(hp), _ep(ep), _ad(ad)
{
	std::cout << "ClapTrap values constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& trap)
{
	*this = trap;
	std::cout << "Claptrap copy constructor called" << std::endl;
}

void	ClapTrap::operator=(const ClapTrap& trap)
{
	this->_name = trap._name;
	this->_hp = trap._hp;
	this->_ep = trap._ep;
	this->_ad = trap._ad;
	std::cout << "Claptrap assignment operator called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::setAttack(uint32_t amount)
{
	this->_ad = amount;
	std::cout << this->_name << "\'s attack has been set to " << amount << std::endl;
}

uint32_t	ClapTrap::getAttack()
{
	return (this->_ad);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack" << std::endl;
	}
	else if (_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target \
			<< " causing " << this->_ad << " points of damage!" << std::endl;
		_ep--;
	}
	else
		std::cout << "ClapTrap " << this->_name << \
			" has insufficient energy points to attack" << std::endl;
}

void	ClapTrap::takeDamage(uint32_t amount)
{
	if (_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount \
			<< " points of damage!" << std::endl;
		if (amount >= _hp)
			_hp = 0;
		else
			_hp -= amount;
	}
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(uint32_t amount)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
	}
	else if (_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount \
			<< " hit points" << std::endl;
		_ep--;
		_hp += amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << \
			" has insufficient energy points to repair itself" << std::endl;
}