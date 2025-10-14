#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int	value;
	static const int fractional_bits = 8;

	public:
// Orthodox Canonical class form
	Fixed();
	Fixed( const Fixed &other );
	Fixed &operator=( const Fixed &other );
	~Fixed();

	Fixed(const int param );
	Fixed(const float param );

	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream &operator<<( std::ostream &os, const Fixed &other );

#endif