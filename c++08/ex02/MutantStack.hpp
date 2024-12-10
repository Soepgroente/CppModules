#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:

	MutantStack() {std::stack()};
	~MutantStack() {std::~stack()};
	MutantStack(const MutantStack& original)
	{
		if (this != &original)
			*this = original;
	};
	MutantStack&	operator=(const MutantStack& original);
};
