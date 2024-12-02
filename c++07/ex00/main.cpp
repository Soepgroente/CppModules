#include <iostream>
#include "Whatever.hpp"

int	main()
{
	int a = 2;
	int b = 3;
	tp::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min (a, b) = " << tp::min(a, b) << std::endl;
	std::cout << "max (a, b) = " << tp::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	tp::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min (c, d) = " << tp::min(c, d) << std::endl;
	std::cout << "max (c, d) = " << tp::max(c, d) << std::endl;
	return (0);
}
