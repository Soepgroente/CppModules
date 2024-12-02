#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

namespace tp
{
	template <typename T>
	int	easyfind(T& container, int toFind)
	{
		return (std::find(container.begin(), container.end(), toFind) - container.begin());
	}
}