#include <iostream>

#pragma once

class	Fixed
{
	public:
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed& original);
	~Fixed();
	void	operator=(const Fixed& original);

	private:

	int					value;
	static const int	fractional_bits = 8;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& original);
