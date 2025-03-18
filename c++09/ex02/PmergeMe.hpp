#pragma once

#include <algorithm>
#include <chrono>
#include <exception>
#include <deque>
#include <iostream>
#include <iterator>
#include <sstream>
#include <thread>
#include <vector>

void	sortInASillyWay(std::vector<int>& vector, std::deque<int>& deque);
void	FordJohnnyVector(std::vector<int>& numbers);
void	FordJohnnyDeque(std::deque<int>& numbers);
void	compareTwoElements(int& a, int& b);

template <typename Container>
void printArray(const Container& container)
{
	for (const auto& element : container)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
size_t	arrayIsSorted(const Container& array)
{
	for (size_t i = 1; i < array.size(); i++)
	{
		if (array[i - 1] > array[i])
		{
			return (i);
		}
	}
	return (0);
}