#pragma once

#include <iostream>

class	Animal
{
	public:

	Animal();
	virtual ~Animal();
	Animal(const Animal& original) = delete;
	void	operator=(const Animal& original) = delete;

	virtual void	makeSound()	const = 0;
	const std::string&	getType() const;

	protected:

	std::string	type;
	void	constructorPrinter(std::string action)	const;
};