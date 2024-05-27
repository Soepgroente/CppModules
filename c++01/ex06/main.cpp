#include <iostream>
#include <iomanip>
#include "Harl.hpp"

#define FOREVER 1

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << ERROR_MSG << std::endl;
		return (1);
	}

	std::string	input;
	Harl		robot(argv[1]);

	if (robot.filter == -1)
	{
		std::cout << ERROR_MSG << std::endl;
		return (1);
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter a level for Harl: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		robot.complain(input);
		std::cout << std::endl;
	}
	std::cout << "[SHUTTING DOWN]" << std::endl;
	return (0);
}