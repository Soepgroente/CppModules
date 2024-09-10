#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main()
{
	Animal* meta;
	Animal* meower;
	Animal* woofer;

	meta = new Animal();
	try
	{
		meower = new Cat();
	}
	catch (std::bad_alloc)
	{
		delete meta;
		return (1);
	}
	try
	{
		woofer = new Dog();
	}
	catch (std::bad_alloc)
	{
		delete meta;
		delete meower;
		return (2);
	}

	std::cout << "Cat is: " << meower->getType() << " " << std::endl;
	std::cout << "Dog is: " << woofer->getType() << std::endl;

	meta->makeSound();
	meower->makeSound();
	woofer->makeSound();

	delete meta;
	delete woofer;
	delete meower;

	std::cout << "\n=============================================\n" << std::endl;

	WrongAnimal* meta2;
	WrongAnimal* meower2;

	meta2 = new WrongAnimal();
	try
	{
		meower2 = new WrongCat();
	}
	catch (std::bad_alloc)
	{
		delete meta2;
		return (3);
	}

	std::cout << "WrongCat is: " << meower2->getType() << " " << std::endl;

	meta2->makeSound();
	meower2->makeSound();

	delete meta2;
	delete meower2;
	
	return (0);
}