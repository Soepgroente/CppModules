#include "MutantStack.hpp"

template<typename T>
void	printArray(T& array)
{
	for (typename T::iterator it = array.begin(); it != array.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);


	printArray(mstack);
	std::cout << "top element: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	printArray(mstack);

	std::cout << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	size_t sizels = s.size();
	for (size_t i = 0; i < sizels; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << std::endl;
	// printArray(s);
	return 0;
}