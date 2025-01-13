#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T>
{
	public:

	MutantStack() {std::stack<T, Container>();}
	~MutantStack() = default;
	MutantStack(const std::stack<T> &value) : std::stack<T>(value) {};
	MutantStack(const MutantStack& original)
	{
		if (this != &original)
			*this = original;
	};
	MutantStack<T>&	operator=(const MutantStack& original)
	{
		if (this != &original)
			this->c = original.c;
		return (*this);
	};

	using iterator = typename std::stack<T>::container_type::iterator;

	iterator	begin()	{return this->c.begin();}
	iterator	end()	{return this->c.end();}
};
