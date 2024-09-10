#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:

	Cat();
	~Cat();
	Cat(const Cat& original);
	Cat&	operator=(const Cat& original);

	void	makeSound() const override;
	void	printThoughts()	const;

	private:
	Brain*	brain;
};