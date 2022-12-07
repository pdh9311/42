#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value) : fixed_point_(value << Fixed::fractional_bits_) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixed_point_(static_cast<int>(roundf(value * (1 << Fixed::fractional_bits_)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Assignation operator called" << std::endl;
	fixed_point_ = fixed.getRawBits();
	return (*this);
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}
