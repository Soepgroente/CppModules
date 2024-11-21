#include "Iter.hpp"

class	TestClass
{
	public:
	TestClass() = default;
	TestClass(int value) {iter = value;}
	~TestClass() = default;

	int	get()	const {return iter;}

	private:
	int iter = 0;
};

std::ostream& operator<<(std::ostream& out, const TestClass& test)
{
	out << test.get();
	return (out);
}

template<typename T>
void	plusOne(T& variable)
{
	variable++;
}

template<typename T>
void	print(const T& variable)
{
	std::cout << variable << " ";
}

int	main()
{
	size_t			array[] = {0, 1, 2, 3, 4};
	const size_t	array2[] = {10, 11, 12, 13, 14, 15, 16};
	char			charray[] = {'a', 'b', 'c'};
	const char		charray2[] = {'d', 'e', 'f', 'g'};
	TestClass		testarray[]{1, 2, 3, 4};

	/*	print, ++ array and print	*/
	iter(array, sizeof(array) / sizeof(size_t), &print);
	std::cout << std::endl;
	iter(array, sizeof(array) / sizeof(size_t), &plusOne);
	iter(array, sizeof(array) / sizeof(size_t), &print);
	std::cout << std::endl;

	/*	print const array	*/
	iter(array2, sizeof(array2) / sizeof(size_t), &print);
	std::cout << std::endl;

	/*	same deal with chars intead of integers	*/
	iter(charray, sizeof(charray) / sizeof(char), &print);
	std::cout << std::endl;
	iter(charray, sizeof(charray) / sizeof(char), &plusOne);
	iter(charray, sizeof(charray) / sizeof(char), &print);
	std::cout << std::endl;

	iter(charray2, sizeof(charray2) / sizeof(char), &print);
	std::cout << std::endl;

	/*	works with a class too	*/
	iter(testarray, sizeof(testarray) / sizeof(TestClass), &print);
	std::cout << std::endl;
}