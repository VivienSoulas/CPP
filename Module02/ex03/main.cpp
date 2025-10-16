#include "Point.hpp"

int main()
{
// inside
	Point a;
	Point b(10, 0);
	Point c(5, 10);
	Point point(5, 3);
	if (bsp(a, b, c, point))
		std::cout << "true\n";
	else
		std::cout << "False\n";

// outside
	Point g(5,-2);
	if (bsp(a, b, c, g))
		std::cout << "True\n";
	else
		std::cout << "False\n";
	return (0);
}