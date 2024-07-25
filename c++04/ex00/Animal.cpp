#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor" << std::endl;
}

void	Animal::makeSound()	const
{
}

std::string	Animal::getType()	const
{
	return (this->type);
}