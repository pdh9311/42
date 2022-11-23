#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const Point& p) {
	*this = p;
}

Point::Point(const float f1, const float f2) : x_(f1), y_(f2) {}

Point::~Point() {}

Point& Point::operator=(const Point& p) {
	const_cast<Fixed&>(x_) = p.getX();
	const_cast<Fixed&>(y_) = p.getY();
	return (*this);
}

const Fixed& Point::getX(void) const {
	return (this->x_);
}

const Fixed& Point::getY(void) const {
	return (this->y_);
}
