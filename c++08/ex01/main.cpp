#include "Span.hpp"

int main()
{
	Span	original(5);

	for (size_t i = 0; i < original.getSize(); i++)
	{
		original.addNumber(i);
	}
	Span	copy = original;

	original.print();
	copy.print();
}