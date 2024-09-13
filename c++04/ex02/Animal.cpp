#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	Animal::constructorPrinter("default constructor");
}

Animal::~Animal()
{
	Animal::constructorPrinter("default deconstructor");
}

void	Animal::makeSound()	const
{
}

const std::string&	Animal::getType()	const
{
	return (this->type);
}

void	Animal::constructorPrinter(std::string action)	const
{
	std::cout << this->type << " " << action << " called" << std::endl;
}