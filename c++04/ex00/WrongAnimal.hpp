#pragma once

#include <iostream>

class	WrongAnimal
{
	public:

	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& original) = delete;
	void	operator=(const WrongAnimal& original) = delete;

	void	makeSound() const;
	std::string		getType() const;

	protected:

	std::string	type;
};