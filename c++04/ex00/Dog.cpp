#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor" << std::endl;
}

Dog::Dog(const Dog& original)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = original;
}

void	Dog::operator=(const Dog& original)
{
	std::cout << "Dog assignment operator" << std::endl;
	if (this == &original)
		return ;
	this->type = original.type;
}

void	Dog::makeSound()	const
{
	std::cout << "Wooooof" << std::endl;
}