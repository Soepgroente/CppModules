#include "Span.hpp"

int main()
{
	Span	original(5);

	for (size_t i = 0; i < original.getSize(); i++)
	{
		original.addNumber(i);
	}
	try
	{
		original.addNumber(82523);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Whoops, array is full" << std::endl;
	}
	Span	copy = original;

	original.print();
	copy.print();
}