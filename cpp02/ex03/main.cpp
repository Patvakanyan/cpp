#include "Point.hpp"
#include <iostream>

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(3, 3);
	Point outside(10, 10);
	Point onEdge(5, 0);
	Point onVertex(0, 0);

	std::cout << "Triangle A(0,0), B(10,0), C(0,10)" << std::endl;
	std::cout << "inside (3,3):      " << (bsp(a, b, c, inside) ? "inside" : "outside") << " (expected: inside)" << std::endl;
	std::cout << "outside (10,10):   " << (bsp(a, b, c, outside) ? "inside" : "outside") << " (expected: outside)" << std::endl;
	std::cout << "on edge (5,0):     " << (bsp(a, b, c, onEdge) ? "inside" : "outside") << " (expected: outside)" << std::endl;
	std::cout << "on vertex (0,0):   " << (bsp(a, b, c, onVertex) ? "inside" : "outside") << " (expected: outside)" << std::endl;

	std::cout << std::endl;
	std::cout << "Same triangle reversed orientation C,B,A" << std::endl;
	std::cout << "inside (3,3):      " << (bsp(c, b, a, inside) ? "inside" : "outside") << " (expected: inside)" << std::endl;

	return 0;
}
