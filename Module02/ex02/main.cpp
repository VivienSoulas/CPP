#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 10.10f ) / 2 );
	Fixed d(6);
	Fixed e(6);
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	a++;
	std::cout << "after a++ = " << a << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	if (a > b)
		std::cout << "a is bigger than b\n";
	else
		std::cout << "a is not bigger than b\n";
	if (a < c)
		std::cout << "a is smaller than c\n";
	else
		std::cout << "a is not smaller than c\n";
	if (e == d)
		std::cout << "e == d\n";
	if (e != a)
		std::cout << "e != a\n";
	std::cout << "\na = " << a << "\nb = " << b << "\nmax is : " << Fixed::max( a, b ) << std::endl;
	std::cout << "\ne = " << e << "\nc = " << c << "\nmin is : " << Fixed::min( e, c ) << std::endl;
	return 0;
}