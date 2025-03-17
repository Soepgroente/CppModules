#include "PmergeMe.hpp"

using Stopwatch = std::chrono::_V2::system_clock::time_point;

static std::time_t	duration(Stopwatch begin, Stopwatch end)
{
	return (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count());
}

void	compareTwoElements(int& a, int& b)
{
	if (a > b)
	{
		std::swap(a, b);
	}
}

template <typename Container, typename Func>
void callSortingAlgorithm(const std::string& message, Func func, Container& container)
{
    Stopwatch begin, end;

    begin = std::chrono::high_resolution_clock::now();
    func(container);
    end = std::chrono::high_resolution_clock::now();
    std::cout << message << duration(begin, end) << "μs" << std::endl;
}

void sortInASillyWay(std::vector<int>& vector, std::deque<int>& deque)
{
	std::vector<int> vectorCopy = vector;
	std::deque<int> dequeCopy = deque;

	// callSortingAlgorithm("std::sort on vector: ", [](std::vector<int>& vec) { std::sort(vec.begin(), vec.end()); }, vectorCopy);
	// callSortingAlgorithm("std::sort on deque: ", [](std::deque<int>& deq) { std::sort(deq.begin(), deq.end()); }, dequeCopy);
	callSortingAlgorithm("Fred-Johnson on vector: ", FreddyJohnnyVector, vector);
	// callSortingAlgorithm("Fred-Johnson on deque: ", FreddyJohnnyDeque<std::deque<int>>, deque);
}