#include "PmergeMe.hpp"

static bool	parse(int argc, char** argv, std::vector<int>& vector, std::deque<int>& deque)
{
	int			number;
	std::string	argument;

	for (int i = 1; i < argc; i++)
	{
		std::istringstream	stream(argv[i]);

		while (stream.eof() == false)
		{
			stream >> argument;
			try
			{
				number = std::stoi(argument);
			}
			catch (std::exception& e)
			{
				std::cerr << "Invalid input: " << e.what() << std::endl;
				return (false);
			}
			vector.push_back(number);
			deque.push_back(number);
		}
	}
	return (true);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " [integers...]" << std::endl;
		return (1);
	}
	std::vector<int>	vector;
	std::deque<int>		deque;

	if (parse(argc, argv, vector, deque) == false)
	{
		return (2);
	}
	sortInASillyWay(vector, deque);
	return (0);
}