#include "Point.hpp"
#include <limits>
#include <ios>

/*
	const Point a(1, 1);
	const Point b(4, 8);
	const Point c(9, 3);

	const Point a(1, 1);
	const Point b(9, 3);
	const Point c(4, 8);

	const Point a(0, 0);
	const Point b(0, 5);
	const Point c(6, 0);
 */
int main(void)
{
	float px , py;
	const Point a(0, 0);
	const Point b(0, 5);
	const Point c(6, 0);

	while (1) {
		std::cout << "input px py > ";
		std::cin >> px >> py;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		const Point p(px, py);
		if (bsp(a, b, c, p))
			std::cout << "The point is inside the triangle" << std::endl;
		else
			std::cout << "The point isn't inside the triangle" << std::endl;
		std::cout << std::endl;
	}

	return (0);
}
