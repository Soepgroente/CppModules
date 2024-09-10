#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main()
{
	Animal* critters[10];

	for (int i = 0; i < 5; i++)
		critters[i] = new Cat();
	for (int i = 5; i < 10; i++)
		critters[i] = new Dog();
	for (int i = 0; i < 10; i++)
		critters[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete critters[i];


	Cat*	meow = new Cat();
	Cat*	meowza = new Cat(*meow);

	delete meow;

	/*	Test deep copy of cat	*/

	meowza->printThoughts();
	delete meowza;

	Dog*	woof = new Dog();
	Dog*	subwoofer = new Dog(*woof);

	delete woof;
	/*	Test deep copy of dog	*/

   	subwoofer->printThoughts();
	delete subwoofer;
}