#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:

	Cat();
	~Cat();
	Cat(const Cat& original);
	void	operator=(const Cat& original);

	void	makeSound() const override;
};