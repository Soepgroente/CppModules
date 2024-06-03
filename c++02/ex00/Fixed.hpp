#pragma once

#include <iostream>

class	Fixed
{
	public:
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed();
	Fixed(const Fixed& original);
	~Fixed();
	void	operator=(const Fixed& original);

	private:
	
	int					value;
	static const int	fractional_bits = 8;
};
