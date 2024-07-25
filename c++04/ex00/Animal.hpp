#pragma once

#include <iostream>

class	Animal
{
	public:

	virtual void makeSound() = 0;
	virtual ~Animal();

	protected:
	
	Animal();
	Animal(const Animal& original) = delete;
	void	operator=(const Animal& original) = delete;

	std::string	type;
};