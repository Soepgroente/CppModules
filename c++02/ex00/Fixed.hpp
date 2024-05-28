#pragma once

#include <iostream>

class	Fixed
{
	public:
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	void	operator=(const Fixed& original);

	Fixed();
	Fixed(const Fixed& original);
	~Fixed();

	private:
	
	int					value;
	static const int	fractional_bits = 8;
};
