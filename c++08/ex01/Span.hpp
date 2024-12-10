#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <utility>

class Span
{
	public:

	Span() = delete;
	Span(uint32_t N);
	~Span() = default;
	Span(const Span& original);
	Span&	operator=(const Span& original);

	void	addNumber(int num);
	void	eraseNumber(size_t index);
	size_t	getSize()	const;
	size_t	getPopulatedSize()	const;
	void	print()	const;

	int		shortestSpan()	const;
	int		largestSpan()	const;

	private:
	std::vector<int>	array;
	size_t				size;
	size_t				maxSize;
};
