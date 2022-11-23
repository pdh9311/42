#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0) {}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(const int value) : fixed_point_(value << Fixed::fractional_bits_) {}

Fixed::Fixed(const float value) : fixed_point_(static_cast<int>(roundf(value * (1 << Fixed::fractional_bits_)))) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& fixed) {
	fixed_point_ = fixed.getRawBits();
	return (*this);
}

Fixed& Fixed::operator++() {
	++(fixed_point_);
	return (*this);
}

Fixed& Fixed::operator--() {
	--(fixed_point_);
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(fixed_point_);
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(fixed_point_);
	return (tmp);
}

int Fixed::getRawBits(void) const {
	return (fixed_point_);
}

void Fixed::setRawBits(const int raw) {
	fixed_point_ = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(fixed_point_) / (1 << Fixed::fractional_bits_));
}

int Fixed::toInt(void) const {
	return (fixed_point_ >> Fixed::fractional_bits_);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

bool operator>(const Fixed& f1, const Fixed& f2) {
	return (f1.getRawBits() > f2.getRawBits());
}
bool operator<(const Fixed& f1, const Fixed& f2) {
	return (f1.getRawBits() < f2.getRawBits());
}
bool operator>=(const Fixed& f1, const Fixed& f2) {
	return (f1.getRawBits() >= f2.getRawBits());
}
bool operator<=(const Fixed& f1, const Fixed& f2) {
	return (f1.getRawBits() <= f2.getRawBits());
}
bool operator==(const Fixed& f1, const Fixed& f2) {
	return (f1.getRawBits() == f2.getRawBits());
}
bool operator!=(const Fixed& f1, const Fixed& f2) {
	return (f1.getRawBits() != f2.getRawBits());
}

Fixed operator+(const Fixed& f1, const Fixed& f2) {
	Fixed temp(f1.toFloat() + f2.toFloat());
	return (temp);
}
Fixed operator-(const Fixed& f1, const Fixed& f2) {
	Fixed temp(f1.toFloat() - f2.toFloat());
	return (temp);
}
Fixed operator*(const Fixed& f1, const Fixed& f2) {
	Fixed temp(f1.toFloat() * f2.toFloat());
	return (temp);
}
Fixed operator/(const Fixed& f1, const Fixed& f2) {
	Fixed temp(f1.toFloat() / f2.toFloat());
	return (temp);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}
