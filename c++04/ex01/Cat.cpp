#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	Animal::constructorPrinter("default constructor");
	type = "Cat";
	brain = new Brain;
}

Cat::~Cat()
{
	Animal::constructorPrinter("default deconstructor");
	delete brain;
}

Cat::Cat(const Cat& original)
{
	Animal::constructorPrinter("copy constructor");
	*this = original;
}

Cat&	Cat::operator=(const Cat& original)
{
	Animal::constructorPrinter("assignment overload operator");
	if (this == &original)
		return (*this);
	this->type = original.type;
	this->brain = new Brain(*original.brain);
	return (*this);
}

void	Cat::makeSound()	const
{
	std::cout << "Mweeeow!" << std::endl;
}

void	Cat::printThoughts()	const
{
	Brain::printThoughts(*this->brain);
}