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

void	mergeBack(std::vector<int>& numbers, size_t left, size_t middle, size_t right)
{
	std::vector<int>	a;
	std::vector<int>	b;
	size_t	i = 0;
	size_t	leftIndex = middle - left + 1;
	size_t	rightIndex = right - middle;

	a.reserve(middle - left + 1);
	b.reserve(right - middle);
	for (i = left; i <= middle; i++)
	{
		a.push_back(numbers[i]);
	}
	for (i = middle + 1; i <= right; i++)
	{
		b.push_back(numbers[i]);
	}
	size_t j = 0, k = 0;

	for (i = left; j < middle && k < middle; i++)
	{
		if (a[j] < b[k])
		{
			numbers[left] = a[j];
			j++;
		}
		else
		{
			numbers[left] = b[k];
			k++;
		}
	}
}

void	divideInHalf(std::vector<int>& numbers, size_t left, size_t right)
{
	int middle = (left + right) / 2;

	if (left >= right)
		return ;
	divideInHalf(numbers, left, middle);
	divideInHalf(numbers, middle + 1, right);
	mergeBack(numbers, left, middle, right);
}

void	FreddyJohnnyVector(std::vector<int>& numbers)
{
	std::vector<int>	a;
	std::vector<int>	b;
	size_t				halfIndex = numbers.size() / 2;

	for (size_t i = 0; i < halfIndex; i++)
	{
		a.push_back(std::min(numbers[i], numbers[halfIndex + i]));
		b.push_back(std::max(numbers[i], numbers[halfIndex + i]));
	}
	divideInHalf(b, 0, halfIndex);
	printArray(b);
}