#include "Dog.hpp"

Dog::Dog() : Animal()
{
	Animal::constructorPrinter("default constructor");
	type = "Dog";
	brain = new Brain;
}

Dog::~Dog()
{
	Animal::constructorPrinter("default deconstructor");
	delete brain;
}

Dog::Dog(const Dog& original)
{
	Animal::constructorPrinter("copy constructor");
	*this = original;
}

Dog&	Dog::operator=(const Dog& original)
{
	Animal::constructorPrinter("assignment overload operator");
	if (this == &original)
		return (*this);
	this->type = original.type;
	this->brain = new Brain(*original.brain);
	return (*this);
}

void	Dog::makeSound()	const
{
	std::cout << "Wooooof" << std::endl;
}

void	Dog::printThoughts()	const
{
	Brain::printThoughts(*this->brain);
}