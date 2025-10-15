#include "Point.hpp"

int main()
{
	Point a;
	Point b(5, 2);
	Point c(10, 7);
	Point point(b);
	if (bsp(a, b, c, point))
		std::cout << "true\n";
	else
		std::cout << "False\n";

	Point d(10, 10);
	Point e(8,8);
	Point f(7,10);
	Point g(9,9);
	if (bsp(d, e, f, g))
		std::cout << "True\n";
	else
		std::cout << "False\n";
	return (0);
}