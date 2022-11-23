#include "Point.hpp"

/* [ vector dot ]
 * (p2.x - p1.x, p2.y - p1.y)
 */
Point operator-(const Point& p1, const Point& p2) {
	const Fixed& p1_x = p1.getX();
	const Fixed& p1_y = p1.getY();
	const Fixed& p2_x = p2.getX();
	const Fixed& p2_y = p2.getY();

	Point vec((p2_x - p1_x).toFloat(), (p2_y - p1_y).toFloat());
	return (vec);
}

/* [ vector cross ]
 * ad - bc
 */
Fixed operator*(const Point& v1, const Point& v2) {
	const Fixed& v1_x = v1.getX();
	const Fixed& v1_y = v1.getY();
	const Fixed& v2_x = v2.getX();
	const Fixed& v2_y = v2.getY();

	Fixed cross((v1_x * v2_y) - (v1_y * v2_x));
	return (cross);
}

bool direction(const Fixed& f) {
	Fixed zero(0);

	if (f > zero)
		return (true);
	return (false);
}

bool bsp(const Point a, const Point b, const Point c, const Point p) {
	Point ap = a - p;
	Point ab = a - b;

	Point bp = b - p;
	Point bc = b - c;

	Point cp = c - p;
	Point ca = c - a;

	Fixed apab = ap * ab;
	Fixed bpbc = bp * bc;
	Fixed cpca = cp * ca;

	if (apab == 0 || bpbc == 0 || cpca == 0)
		return (false);
	if ((direction(apab) && direction(bpbc) && direction(cpca))
		|| (!direction(apab) && !direction(bpbc) && !direction(cpca)))
		return (true);
	return (false);
}
