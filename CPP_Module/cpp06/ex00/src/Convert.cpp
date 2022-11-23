#include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(const char *str) {
	char *strEnd = NULL;

	value_ = std::strtod(str, &strEnd);
	error_ = false;
	if (*strEnd && std::strcmp(strEnd, "f")) {
		error_ = true;
	}
	c_ = static_cast<char>(value_);
	i_ = static_cast<int>(value_);
	f_ = static_cast<float>(value_);
	d_ = static_cast<double>(value_);
}
Convert::Convert(const Convert &convert) {
	*this = convert;
}

Convert::~Convert() {}

Convert& Convert::operator=(const Convert &convert) {
	value_ = convert.getValue();
	error_ = convert.getError();
	c_ = convert.getC();
	i_ = convert.getI();
	f_ = convert.getF();
	d_ = convert.getD();
	return (*this);
}

const double& Convert::getValue() const {
	return (value_);
}
const bool& Convert::getError() const {
	return (error_);
}
const char& Convert::getC() const {
	return (c_);
}
const int& Convert::getI() const {
	return (i_);
}
const float& Convert::getF() const {
	return (f_);
}
const double& Convert::getD() const {
	return (d_);
}


void Convert::printChar() {
	std::cout << "char: ";
	if (std::isnan(value_) || std::isinf(value_)
		|| i_ > std::numeric_limits<char>::max()
		|| i_ < std::numeric_limits<char>::min()
		|| error_ == true) {
		std::cout << "impossible" << std::endl;
	} else if (i_ < 32 || i_ == 127) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << c_ << "'" << std::endl;
	}
}

void Convert::printInt() {
	std::cout << "int: ";
	long tmp = static_cast<long>(value_);
	if (std::isnan(value_) || std::isinf(value_)
		|| tmp > std::numeric_limits<int>::max()
		|| tmp < std::numeric_limits<int>::min()
		|| error_ == true) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << i_ << std::endl;
	}
}

void Convert::printFloat() {
	std::cout << "float: ";
	double diff = fabs(f_ - i_);
	if (d_ > std::numeric_limits<float>::max()
		|| d_ < -std::numeric_limits<float>::max()
		|| error_ == true) {
		std::cout << "impossible" << std::endl;
	} else if (diff == 0 || diff < 1e-6) {
		std::cout << i_ << ".0f" << std::endl;
	} else {
		std::cout << f_ << "f" << std::endl;
	}
}

void Convert::printDouble() {
	std::cout << "double: ";
	double diff = fabs(d_ - i_);
	long double tmp = static_cast<long double>(value_);
	if (tmp > std::numeric_limits<double>::max()
		|| tmp < -std::numeric_limits<double>::max()
		|| error_ == true) {
		std::cout << "impossible" << std::endl;
	} else if (diff == 0 || diff < 1e-6) {
		std::cout << i_ << ".0" << std::endl;
	} else {
		std::cout << d_ << std::endl;
	}
}

void Convert::printCovert() {
	void (Convert::*fn[4])() = {&Convert::printChar, &Convert::printInt, &Convert::printFloat, &Convert::printDouble};
	for (int i = 0; i < 4; i++) {
		(this->*fn[i])();
	}
}
