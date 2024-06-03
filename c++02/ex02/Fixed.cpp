#include <iostream>
#include <iomanip>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	this->value = original.value;
}

Fixed::Fixed(const int val)
{
	value = val << fractional_bits;
}

Fixed::Fixed(const float val)
{
	value = (int)std::roundf(val * (1 << fractional_bits));
}

Fixed::~Fixed()
{
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

/*	===================================================================	*/
/*							Operator overloads							*/
/*	===================================================================	*/

void	Fixed::operator=(const Fixed& original)
{
	this->setRawBits(original.getRawBits());
}

bool	Fixed::operator<(const Fixed& fn)
{
	if (fn.getRawBits() < this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& fn)
{
	if (fn.getRawBits() > this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& fn)
{
	if (fn.getRawBits() <= this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& fn)
{
	if (fn.getRawBits() >= this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& fn)
{
	if (fn.getRawBits() == this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& fn)
{
	if (fn.getRawBits() != this->getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& fn)
{
	return (Fixed(this->getRawBits() + fn.getRawBits()));
}

Fixed	Fixed::operator-(const Fixed& fn)
{
	return (Fixed(this->getRawBits() - fn.getRawBits()));
}

Fixed	Fixed::operator*(const Fixed& fn)
{
	Fixed	product;

	long	tmp = ((long)this->getRawBits() * fn.getRawBits()) >> fractional_bits;
	product.setRawBits((int)tmp);
	return (product);
}

Fixed	Fixed::operator/(const Fixed& fn)
{
	Fixed	division;

	long	tmp = (((long)this->getRawBits() << fractional_bits) / fn.getRawBits());
	division.setRawBits((int)tmp);
	return (division);
}

Fixed&	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fn)
{
	stream << fn.toFloat();
	return (stream);
}