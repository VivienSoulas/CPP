#include "Fixed.hpp"

// Operator overload for printing
std::ostream &operator<<(std::ostream &os, const Fixed &other )
{
	return (os << other.toFloat());
}
// Operator overload for printing


// Comparaison Operator Overlaods
bool Fixed::operator>( const Fixed &other ) const
{
	return (this->value > other.value);
}

bool Fixed::operator<( const Fixed &other ) const
{
	return (this->value < other.value);
}

bool Fixed::operator>=( const Fixed &other ) const
{
	return (this->value >= other.value);
}

bool Fixed::operator<=( const Fixed &other ) const
{
	return (this->value <= other.value);
}

bool Fixed::operator==( const Fixed &other ) const
{
	return (this->value == other.value);
}

bool Fixed::operator!=( const Fixed &other ) const
{
	return (this->value != other.value);
}
// Comparaison Operator Overlaods


// Arithmetic Operator Overload
Fixed Fixed::operator+( const Fixed &other ) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits()); 
	return (result);
}

Fixed Fixed::operator-( const Fixed &other ) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*( const Fixed &other ) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * other.getRawBits()) >> fractional_bits);
	return (result);
}

Fixed Fixed::operator/( const Fixed &other ) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << fractional_bits) / other.getRawBits());
	return (result);
}

Fixed &Fixed::operator++()
{
	int value;
	value = this->getRawBits();
	value++;
	this->setRawBits(value);
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}
// Arithmetic Operator Overload


// Min and Max overload
Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a > b)
		return (a);
	return (b);
}
// Min and Max overload