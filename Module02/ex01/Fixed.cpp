#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout	<< "Default constructor called"
				<< std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
	*this = other;
}

Fixed::Fixed( const int param )
{
	std::cout	<< "Int constructor called"
				<< std::endl;
	this->value = param << fractional_bits;
}

Fixed::Fixed (const float param )
{
	std::cout	<< "Float constructor called"
				<< std::endl;
	this->value = roundf(param * (1 << this->fractional_bits));
}



Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}




Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout	<< "Copy assigmet operator called"
				<< std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

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





std::ostream &operator<<(std::ostream &os, const Fixed &other )
{
	return (os << other.toFloat());
}