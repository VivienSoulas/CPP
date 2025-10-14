#include "Fixed.hpp"

#include <iostream>
int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;
	////set raw data to b to check if c keeps the value
	//b.setRawBits(5);
	//std::cout << std::endl;
	//std::cout << a.getRawBits() << std::endl;
	//std::cout << b.getRawBits() << std::endl;
	//std::cout << c.getRawBits() << std::endl;
	//std::cout << std::endl;
	//a.setRawBits(9);
	//std::cout << std::endl;
	//std::cout << a.getRawBits() << std::endl;
	//std::cout << b.getRawBits() << std::endl;
	//std::cout << c.getRawBits() << std::endl;
	//std::cout << std::endl;
	return 0;
}
