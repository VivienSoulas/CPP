#include "Point.hpp"

int main()
{
	Point a;
	Point b(10, 0);
	Point c(5, 10);

// edge
	Point point(a);
	if (bsp(a, b, c, point))
		std::cout << "True\n";
	else
		std::cout << "False\n";

// inside
	Point d(8, 5);
	if (bsp(a, b, c, d))
		std::cout << "True\n";
	else
		std::cout << "False\n";

// outside
	Point e(5,-2);
	if (bsp(a, b, c, e))
		std::cout << "True\n";
	else
		std::cout << "False\n";

// on the same vector as AB, but outside the triangle
	Point f(-5,0);
	if (bsp(a, b, c, f))
		std::cout << "True\n";
	else
		std::cout << "False\n";

	return (0);
}