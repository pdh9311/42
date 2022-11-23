#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Assignation operator called" << std::endl;
	fixed_point_ = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits memeber function called" << std::endl;
	return (fixed_point_);
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits memeber function called" << std::endl;
	fixed_point_ = raw;
}