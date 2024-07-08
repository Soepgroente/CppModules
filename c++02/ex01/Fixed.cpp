#include <iostream>
#include <iomanip>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	value = val << fractional_bits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	value = (int)std::roundf(val * (1 << fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (this->value >> fractional_bits);
}

float Fixed::toFloat(void) const
{
	return (this->getRawBits() / (float)(1 << fractional_bits));
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

void	Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = original.getRawBits();
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& original)
{
	stream << original.toFloat();
	return (stream);
}