#include "PmergeMe.hpp"

static void	binarySearchAndInsert(std::vector<int>& array, int numToInsert, size_t left, size_t right)
{
	size_t	middle = left + (right - left) / 2;

	while (left < right)
	{
		if (numToInsert > array[middle])
		{
			left = middle + 1;
		}
		else
		{
			right = middle;
		}
		middle = left + (right - left) / 2;
	}
	array.insert(array.begin() + left, numToInsert);
}

static void	andConquer
(
	std::vector<std::pair<int, int>>& pair1, 
	std::vector<std::pair<int, int>>& pair2, 
	std::vector<std::pair<int, int>>& insertInto
)
{
	size_t	index1 = 0;
	size_t	index2 = 0;
	size_t	size1 = pair1.size();
	size_t	size2 = pair2.size();

	insertInto.clear();
	while (index1 < size1 && index2 < size2)
	{
		if (pair1[index1].second < pair2[index2].second)
		{
			insertInto.push_back(pair1[index1]);
			index1++;
		}
		else
		{
			insertInto.push_back(pair2[index2]);
			index2++;
		}
	}
	while (index1 < size1)
	{
		insertInto.push_back(pair1[index1]);
		index1++;
	}
	while (index2 < size2)
	{
		insertInto.push_back(pair2[index2]);
		index2++;
	}
}

static void	divide(std::vector<std::pair<int, int>>& pairs)
{
	if (pairs.size() <= 1)
	{
		return ;
	}
	std::vector<std::pair<int, int>>	pairs1, pairs2;
	size_t	half = pairs.size() / 2;

	pairs1.reserve(half);
	pairs2.reserve(half);
	pairs1.insert(pairs1.begin(), pairs.begin(), pairs.begin() + half);
	pairs2.insert(pairs2.begin(), pairs.begin() + half, pairs.end());
	divide(pairs1);
	divide(pairs2);
	andConquer(pairs1, pairs2, pairs);
}

static std::vector<int>	copyHigherHalf(std::vector<std::pair<int, int>>& pairs)
{
	std::vector<int>	result;

	result.reserve(pairs.size());
	for (const std::pair<int, int>& pair : pairs)
	{
		result.push_back(pair.second);
	}
	return (result);
}

static std::vector<int>	copyLowerHalf(std::vector<std::pair<int, int>>& pairs)
{
	std::vector<int>	result;

	result.reserve(pairs.size());
	for (const std::pair<int, int>& pair : pairs)
	{
		result.push_back(pair.first);
	}
	return (result);
}

static std::vector<int>	insertLowerHalf(std::vector<std::pair<int, int>>& pairs)
{
	std::vector<int>	result = copyHigherHalf(pairs);
	std::vector<int> 	toInsert = copyLowerHalf(pairs);
	size_t				totalSize = pairs.size() * 2;
	size_t				insertedElements = 0;
	size_t				index, prevIndex, jacobsthalNumber;

	result.insert(result.begin(), toInsert[0]);
	insertedElements++;
	index = 1;
	prevIndex = 0;
	if (toInsert.size() == 1)
	{
		return (result);
	}
	binarySearchAndInsert(result, toInsert[1], 0, 2);
	insertedElements++;
	while (result.size() < totalSize)
	{
		jacobsthalNumber = std::min(prevIndex + 2 * index, toInsert.size() - 1);
		prevIndex = index;
		while (jacobsthalNumber > index)
		{
			binarySearchAndInsert(result, toInsert[jacobsthalNumber - (jacobsthalNumber - index)], 0, jacobsthalNumber + insertedElements);
			insertedElements++;
			index++;
		}
	}
	return (result);
}

void	FordJohnnyVector(std::vector<int>& numbers)
{
	std::vector<std::pair<int, int>>	pairs;
	std::vector<int>					result;

	result.reserve(numbers.size());

	for (size_t i = 0; i < numbers.size() - 1; i += 2)
	{
		pairs.push_back({std::min(numbers[i], numbers[i + 1]), \
						std::max(numbers[i], numbers[i + 1])});
	}
	divide(pairs);
	result = insertLowerHalf(pairs);
	if (numbers.size() % 2 != 0)
	{
		binarySearchAndInsert(result, numbers.back(), 0, numbers.size() - 1);
	}
	numbers = result;
}