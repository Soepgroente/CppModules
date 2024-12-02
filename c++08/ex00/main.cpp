#include "easyfind.hpp"

int main()
{
	std::array<int, 7>	array = {-1, 0, 1, 2, 3, 4, 5};
	std::vector<int>	vec;

	for (int i = 0; i < 12; i++)
	{
		vec.emplace_back(5 * i);
	}
	std::cout << "3 in array index: " << tp::easyfind(array, 3) << std::endl;
	std::cout << "40 in vector index: " << tp::easyfind(vec, 40) << std::endl;
}