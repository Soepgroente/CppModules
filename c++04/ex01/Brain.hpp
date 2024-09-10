#pragma once

#include <iostream>

class Brain
{
	public:

	Brain();
	~Brain();
	Brain(const Brain& original);
	Brain&	operator=(const Brain& original);

	void				setIdea(const std::string& idea);
	const std::string&	getIdea(int position)	const;
	void				populateBrain();

	static void			printThoughts(const Brain& brain);

	private:

	std::string*		ideas;
	const static int	totalThoughts;

	void				constructorPrinter(std::string action)	const;
	static std::string	randomIdea();
};