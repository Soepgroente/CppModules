#include "PmergeMe.hpp"

/*	Step 1: Group the elements of into n / 2 pairs of elements, arbitrarily, 
	leaving one element unpaired if there is an odd number of elements. */

/*	Step 2: Perform comparisons, one per pair, to determine the larger of the two elements in each pair.	*/

/*	Step 3: Recursively sort the larger elements from each pair, 
	creating a sorted sequence of the input elements, 
	in ascending order, using the merge-insertion sort.	*/

/*	Step 4: Insert at the start of S the element that was paired with the first and smallest element of S	*/

/*	Step 5: Insert the remaining elements of S into S, 
	one at a time, with a specially chosen insertion ordering described below. 
	Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.	*/

static void	binarySearchAndInsert(std::vector<int>& array, int numToInsert, size_t end)
{
	size_t	half = array.size() / 2;
	size_t	index = half;
	size_t	prevIndex = half;

	while (half > 0 && numToInsert != array[index])
	{
		if (numToInsert > array[index])
		{
			index += half / 2;
		}
		else
		{
			index -= half / 2;
		}
		prevIndex = index;
		half /= 2;
	}
	array.insert(array.begin() + index, numToInsert);
}

/*	Creates a new sorted array combining two arrays	*/

static void	andConquer(std::vector<int>& array1, std::vector<int>& array2, std::vector<int>& insertInto)
{
	size_t	index1 = 0;
	size_t	index2 = 0;
	size_t	size1 = array1.size();
	size_t	size2 = array2.size();

	insertInto.clear();
	while (index1 < size1 && index2 < size2)
	{
		if (array1[index1] < array2[index2])
		{
			insertInto.push_back(array1[index1]);
			index1++;
		}
		else
		{
			insertInto.push_back(array2[index2]);
			index2++;
		}
	}
	while (index1 < size1)
	{
		insertInto.push_back(array1[index1]);
		index1++;
	}
	while (index2 < size2)
	{
		insertInto.push_back(array2[index2]);
		index2++;
	}
}

/*	Recursively divides the array in half until size is 1 (therefore sorted)	*/

static void	divide(std::vector<int>& numnumnum)
{
	if (numnumnum.size() <= 1)
	{
		return ;
	}
	std::vector<int>	array1;
	std::vector<int>	array2;
	size_t				half = numnumnum.size() / 2;

	array1.reserve(half);
	array2.reserve(half);
	array1.insert(array1.begin(), numnumnum.begin(), numnumnum.begin() + half);
	array2.insert(array2.begin(), numnumnum.begin() + half, numnumnum.end());
	divide(array1);
	divide(array2);
	andConquer(array1, array2, numnumnum);
}

static std::vector<int>	insertLowerHalf(std::vector<int>& small, std::vector<int>& large)
{
	const std::vector<size_t>	jacobsthalSequence = calculateJacobsthalSequence();

	std::vector<int>	result = large;
	size_t				index = 3, prevIndex = 1;
	int					seqIndex = 3;

	binarySearchAndInsert(result, small[0], result.size() - 1);
	binarySearchAndInsert(result, small[1], result.size() - 1);
	while (prevIndex != index)
	{
		while (index > jacobsthalSequence[prevIndex])
		{
			binarySearchAndInsert(result, small[index], result.size() - 1);
			index--;
		}
		prevIndex = std::min(jacobsthalSequence[seqIndex], small.size() - 1);
		seqIndex++;
		index = std::min(jacobsthalSequence[seqIndex], small.size() - 1);
	}
	return (result);
}

void	FreddyJohnnyVector(std::vector<int>& numbers)
{
	std::vector<int>	smallNumbers;
	std::vector<int>	largeNumbers;
	std::vector<int>	result;

	result.reserve(numbers.size());

	for (size_t i = 0; i < numbers.size() - 1; i += 2)
	{
		smallNumbers.push_back(std::min(numbers[i], numbers[i + 1]));
		largeNumbers.push_back(std::max(numbers[i], numbers[i + 1]));
	}
	printArray(smallNumbers);
	printArray(largeNumbers);
	divide(largeNumbers);
	result = insertLowerHalf(smallNumbers, largeNumbers);
	if (numbers.size() % 2 != 0)
	{
		binarySearchAndInsert(result, numbers.back(), numbers.size() - 1);
	}
	numbers = result;
	printArray(numbers);
}