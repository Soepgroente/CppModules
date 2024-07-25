#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor" << std::endl;
}

Cat::Cat(const Cat& original)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = original;
}

void	Cat::operator=(const Cat& original)
{
	std::cout << "Cat assignment operator" << std::endl;
	if (this == &original)
		return ;
	this->type = original.type;
}

void	Cat::makeSound()	const
{
	std::cout << "Mweeeow!" << std::endl;
}