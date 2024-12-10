#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

namespace tp
{
	template <typename T>
	size_t	easyfind(T& container, int toFind)
	{
		typename T::iterator	it;

		it = std::find(container.begin(), container.end(), toFind);
		if (it == container.end())
			return (SIZE_MAX);
		return (it - container.begin());
	}
}
