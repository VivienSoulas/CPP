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
	Fixed();
	Fixed( const Fixed &other );
	Fixed &operator=( const Fixed &other );
	~Fixed();

	Fixed( const int param );
	Fixed( const float param );

	float tFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBit( int const raw );

	Fixed &operator>( const Fixed &other );
	Fixed &operator<( const Fixed &other );
	Fixed &operator>=( const Fixed &other );
	Fixed &operator<=( const Fixed &other );
	Fixed &operator==( const Fixed &other );
	Fixed &operator!=( const Fixed &other );

	Fixed &operator+( const Fixed &other );
	Fixed &operator-( const Fixed &other );
	Fixed &operator*( const Fixed &other );
	Fixed &operator/( const Fixed &other );

	//i++;
	//i--;
	//--i;
	//++i;

	Fixed &min( const Fixed &a, const Fixed &b );
};

std::ostream &operator<<( std::ostream& os, const Fixed &other );

#endif