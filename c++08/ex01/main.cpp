#include "Span.hpp"

int main()
{
	/*	Test from subject	*/
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	/*	Additional tests	*/
	Span	original(5);

	for (size_t i = 0; i < original.getMaxSize(); i++)
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

	Span	random(25000);

	random.populate();
	std::cout << "Shortest span: " << random.shortestSpan() << std::endl;
	std::cout << "Longest span: " << random.longestSpan() << std::endl;
}