#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed x_;
	const Fixed y_;

public:
	Point();
	Point(const Point& p);
	Point(const float f1, const float f2);
	~Point();

	Point& operator=(const Point& p);

	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
};

Point operator-(const Point& p1, const Point& p2);
Fixed operator*(const Point& v1, const Point& v2);

bool direction(const Fixed& f);
bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
