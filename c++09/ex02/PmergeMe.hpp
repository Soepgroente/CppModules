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
