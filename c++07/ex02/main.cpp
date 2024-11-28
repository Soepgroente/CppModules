#include "Array.hpp"

int main()
{
	Array<int>	array(5);
	Array<std::string> strings(3);

	for (uint32_t i = 0; i <= array.size(); i++)
	{
		try
		{
			array[i] = i;
		}
		catch (std::exception& e)
		{
			std::cout << "whoops, " << i << " is out of bounds" << std::endl;
		}
	}
	std::cout << array << std::endl;

	strings[0] = "Hello\n";
	strings[1] = "What\n";
	strings[2] = "I'm a template";

	std::cout << strings << std::endl;
}