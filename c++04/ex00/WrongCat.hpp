#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& original);
	void	operator=(const WrongCat& original);

	void	makeSound()	const;
};