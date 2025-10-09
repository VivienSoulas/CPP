#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int	value;
	static const int fractional_bits = 8;

	public:
	Fixed();
	Fixed( const Fixed &other );
	Fixed &operator=( const Fixed &other );
	~Fixed();

	Fixed (const int param );
	Fixed (const float param);
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed &operator<<( const Fixed &other );
//An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif