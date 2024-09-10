#include "Brain.hpp"
#include <iostream>
#include <random>
#include <string>

const int	Brain::totalThoughts = 100;

Brain::Brain()
{
	Brain::constructorPrinter("default constructor");
	ideas = new std::string[totalThoughts]();
	this->populateBrain();
}

Brain::~Brain()
{
	Brain::constructorPrinter("default deconstructor");
	delete[] ideas;
}

Brain::Brain(const Brain& original)
{
	Brain::constructorPrinter("copy constructor");
	*this = original;
}

Brain&	Brain::operator=(const Brain& original)
{
	Brain::constructorPrinter("assignment operator overload");
	if (this == &original)
		return (*this);
	this->ideas = new std::string[totalThoughts]();
	for (int i = 0; i < totalThoughts; i++)
		this->ideas[i] = original.ideas[i];
	return (*this);
}

void	Brain::setIdea(const std::string& idea)
{
	static int pos = 0;

	if (pos == totalThoughts)
		pos = 0;
	this->ideas[pos] = idea;
	pos++;
}

const std::string&	Brain::getIdea(int position)	const
{
	return (this->ideas[position]);
}

void	Brain::populateBrain()
{
	for (int i = 0; i < totalThoughts; i++)
	{
		ideas[i] = randomIdea();
	}
	ideas[totalThoughts / 3] = "I MIGHT HAVE ADHD MEOW WOOF BARK";
}

std::string	Brain::randomIdea()
{
    const static char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string				random_str;
    static	std::mt19937	generator{std::random_device{}()};
    static	std::uniform_int_distribution<std::string::size_type> singleChar(0, sizeof(chars) - 2);
	int length = 10;

    random_str.reserve(length);
    while (length > 0)
	{
        random_str += chars[singleChar(generator)];
		length--;
	}
    return (random_str);
}

void	Brain::printThoughts(const Brain& brain)
{
	for (int i = 0; i < totalThoughts; i++)
	{
		std::cout << brain.ideas[i] << std::endl;
	}
}

void	Brain::constructorPrinter(std::string action)	const
{
	std::cout << "Brain " << action << " called" << std::endl;
}