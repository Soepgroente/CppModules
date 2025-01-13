#include "Span.hpp"
#include <random>
#include <climits>

Span::Span(uint32_t N) : maxSize(N)
{
	size = 0;
}

Span::Span(const Span& original)
{
	if (this != &original)
		*this = original;
}

Span&	Span::operator=(const Span& original)
{
	this->size = original.size;
	this->array = original.array;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (size == maxSize)
		throw std::out_of_range("Amount of elements exceeds defined size");
	array.push_back(num);
	size++;
}

void	Span::eraseNumber(size_t index)
{
	if (index > size - 1)
		throw std::out_of_range("Element to delete doesn't exist");
	array.erase(array.begin() + index);
	size--;
}

size_t	Span::getSize()	const
{
	return (size);
}

size_t	Span::getMaxSize()	const
{
	return (maxSize);
}

void	Span::print()	const
{
	for (size_t i = 0; i < getSize(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int		Span::shortestSpan()	const
{
	if (size < 2)
		throw std::length_error("Array too small to have a span");
	std::vector<int>	tmp = array;
	int result = INT_MAX;

	std::sort(tmp.begin(), tmp.end());

	for (size_t i = 1; i < tmp.size(); i++)
	{
		result = std::min(result, tmp[i] - tmp[i - 1]);
	}
	return (result);
}

int		Span::longestSpan()	const
{
	if (size < 2)
		throw std::length_error("Array too small to have a span");

	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> res;
	
	res = std::minmax_element(array.begin(), array.end());
	return (std::abs(*res.second - *res.first));
}

void	Span::populate()
{
	static	std::mt19937	generator{std::random_device{}()};
	static	std::uniform_int_distribution<int> randomInt(INT_MIN, INT_MAX);

	for (size_t i = getSize(); i < getMaxSize(); i++)
	{
		array.push_back(randomInt(generator));
	}
	size = maxSize;
}