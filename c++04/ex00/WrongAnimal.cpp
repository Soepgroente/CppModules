#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor" << std::endl;
}

void	WrongAnimal::makeSound()	const
{
	std::cout << "..." << std::endl;
}

std::string	WrongAnimal::getType()	const
{
	return (this->type);
}