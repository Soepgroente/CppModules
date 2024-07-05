#include <iostream>

#pragma once

class	Fixed
{
	private:
		int					value;
		static const int	fractional_bits = 8;

	public:
	
	int		getRawBits() const;
	void	setRawBits(int const raw);
	int		toInt() const;
	float	toFloat() const;
	void	abs();

	void	operator=(const Fixed& original);

	bool	operator>(const Fixed& fn);
	bool	operator<(const Fixed& fn);
	bool	operator<=(const Fixed& fn);
	bool	operator>=(const Fixed& fn);
	bool	operator==(const Fixed& fn);
	bool	operator!=(const Fixed& fn);

	Fixed	operator+(const Fixed& fn);
	Fixed	operator-(const Fixed& fn);
	Fixed	operator*(const Fixed& fn);
	Fixed	operator/(const Fixed& fn);

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed&			min(Fixed& a, Fixed& b);
	static const Fixed&		min(const Fixed& a, const Fixed& b);
	static Fixed&			max(Fixed& a, Fixed& b);
	static const Fixed&		max(const Fixed& a, const Fixed& b);

	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed& original);
	~Fixed();
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fn);