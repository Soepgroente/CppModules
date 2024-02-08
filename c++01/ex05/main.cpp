#include <iostream>
#include "Harl.hpp"

int	main(int argc, char** argv)
{
	Harl	robot;

	if (argc < 2)
		std::cout << "Please enter some commands for Harl!" << std::endl;
	for (int i = 1; argv[i] != nullptr; i++)
	{
		std::cout << "Message " << i << ":";
		robot.complain(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}