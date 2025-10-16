#include "Fixed.hpp"

/*============================================================================*/

// Orthodox Canonical class form
Fixed::Fixed()
{
	// std::cout	<< "Default constructor called"
	// 			<< std::endl;
	value = 0;
}

Fixed::Fixed( const Fixed &other )
{
	// std::cout	<< "Copy constructor called"
	// 			<< std::endl;
	*this = other;
}

Fixed &Fixed::operator=( const Fixed &other )
{
	// std::cout	<< "Copy assigmet operator called"
	// 			<< std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout	<< "Destructor called"
	// 			<< std::endl;
}
// Orthodox Canonical class form

/*============================================================================*/

// Specific constructors
Fixed::Fixed( const int param )
{
// 	std::cout	<< "Int constructor called"
// 				<< std::endl;
	this->value = param << fractional_bits;
}

Fixed::Fixed (const float param )
{
	// std::cout	<< "Float constructor called"
	// 			<< std::endl;
	this->value = roundf(param * (1 << this->fractional_bits));
}
// Specific constructors

/*============================================================================*/

// Class functions
int Fixed::getRawBits( void ) const
{
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)value / (1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (value >> fractional_bits);
}
// Class functions

/*============================================================================*/

// Operator overload for printing
std::ostream &operator<<(std::ostream &os, const Fixed &other )
{
	return (os << other.toFloat());
}
// Operator overload for printing

/*============================================================================*/

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

/*============================================================================*/

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

/*============================================================================*/

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

/*============================================================================*/