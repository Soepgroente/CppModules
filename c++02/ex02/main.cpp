#include <iostream>
#include <stdio.h>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(10.0f) * Fixed(8));
	Fixed x(1000000);
	Fixed y(0.2f);
	Fixed c(x / y);

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;

	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << c << std::endl;
	std::cout << (Fixed(1) / Fixed(0.5f)) << std::endl;
	return (0);
}

/* int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
} */