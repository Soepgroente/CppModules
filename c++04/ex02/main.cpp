#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

/*	Animal doesn't work by itself anymore */

int	main()
{
	// Animal	random;
	Animal*	yoink = new Dog();
	Dog		woofboy;
	Cat		meowgirl;

	std::cout << "Animal pointer: " << yoink->getType() << std::endl;
	delete yoink;
	std::cout << "I'm a dog: " << woofboy.getType() << std::endl;
	std::cout << "I'm a cat! " << meowgirl.getType() << std::endl;
}