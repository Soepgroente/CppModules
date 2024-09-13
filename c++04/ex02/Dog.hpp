#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:

	Dog();
	~Dog();
	Dog(const Dog& original);
	Dog&	operator=(const Dog& original);

	void	makeSound() const override;

	void	printThoughts()	const;

	private:

	Brain*	brain;
};