#include "Span.hpp"

Span::Span(uint32_t N) : maxSize(N)
{
	array.reserve(N);
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
	array.emplace_back(num);
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

void	Span::print()	const
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i];
	std::cout << std::endl;
}

int		Span::shortestSpan()	const
{
	if (size < 2)
		throw std::length_error("Array too small to have a span");
	std::vector<int>	tmp = array;

	std::sort(tmp.begin(), tmp.end());
	int result = tmp[1] - tmp[0];

	for (size_t i = 2; i < tmp.size(); i++)
	{
		result = std::min(result, tmp[i] - tmp[i - 1]);
	}
	return (result);
}

int		Span::largestSpan()	const
{
	if (size < 2)
		throw std::length_error("Array too small to have a span");
	int min = *std::min_element(array.begin(), array.end());
	int max = *std::max_element(array.begin(), array.end());
	return (max - min);
}
