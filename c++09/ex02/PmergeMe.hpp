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
void	FreddyJohnnyVector(std::vector<int>& numbers);
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

constexpr const std::vector<size_t>	calculateJacobsthalSequence()
{
	std::vector<size_t>	sequence;
	size_t				num = 0;

	sequence.push_back(0);
	sequence.push_back(1);
	for (size_t n = 2; num < INT_MAX; n++)
	{
		num = sequence[n - 1] + 2 * sequence[n - 2];
		sequence.push_back(num);
	}
	return (sequence);
}