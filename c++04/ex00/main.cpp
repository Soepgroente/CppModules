#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main()
{
	Cat	henry;
	Dog	sjon;
	Dog hans = sjon;

	henry.makeSound();
	sjon.makeSound();
	hans.makeSound();
}