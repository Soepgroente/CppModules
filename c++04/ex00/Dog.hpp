#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:

	Dog();
	~Dog();
	Dog(const Dog& original);
	void	operator=(const Dog& original);

	void	makeSound() const override;
};