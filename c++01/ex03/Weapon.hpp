#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
	
	const std::string&	getType();
	void				setType(std::string new_type);
	Weapon();
	Weapon(std::string name);
	~Weapon();
	
	private:
	
	std::string	type;
};

#endif