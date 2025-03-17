#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error, incorrect number of arguments. Usage: ./RPN \"1 5 - 3 + 4 *\"" << std::endl;
		return (1);
	}
	std::cout << calculate(argv[1]) << std::endl;
	return (0);
}