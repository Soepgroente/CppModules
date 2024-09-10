#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& original)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = original;
}

void	WrongCat::operator=(const WrongCat& original)
{
	std::cout << "WrongCat assignment operator" << std::endl;
	if (this == &original)
		return ;
	this->type = original.type;
}

void	WrongCat::makeSound()	const
{
	std::cout << "Mweeeow!" << std::endl;
}