#include <iostream>
#include <iomanip>
#include <string>
#include "Zombie.hpp"

size_t	ft_atoi(std::string& input)
{
	size_t	N;

	try
	{
        N = std::stoi(input);
    }
	catch (std::exception& e)
	{
		std::cout << "Please insert a valid amount" << std::endl;
		return (0);
    }
	return (N);
}

int	main(void)
{
	Zombie*		Horde;
	std::string	num;
	size_t		N;

	std::cout << "Please insert # of zombies in the horde" << std::endl;
	getline(std::cin, num);
	N = ft_atoi(num);
	if (N > 1000000)
		std::cout << "Please insert a reasonable amount of zombies, I don't want to die" << std::endl;
	else
	{
		Horde = zombieHorde(N, "Harry");
		for (size_t i = 0; i < N; i++)
			Horde[i].announce();
		delete[] Horde;
	}
	return (0);
}
