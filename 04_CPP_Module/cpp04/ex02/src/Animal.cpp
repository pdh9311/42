#include "Animal.hpp"

Animal::Animal() {
	this->type_ = "Animal";
	std::cout << C_AQUA << "Animal " << C_GREEN << "Default Constructor" << C_NC << std::endl;
};

Animal::Animal(const Animal &animal) {
	*this = animal;
	std::cout << C_AQUA << "Animal " << C_GREEN << "Copy Constructor" << C_NC << std::endl;
}

Animal::~Animal() {
	std::cout << C_AQUA << "Animal " << C_RED << "Destructor" << C_NC << std::endl;
};

Animal& Animal::operator=(const Animal &animal) {
	this->type_ = animal.getType();
	return (*this);
}

std::string Animal::getType(void) const {
	return (this->type_);
}

void Animal::setType(const std::string &type) {
	this->type_ = type;
}

std::ostream& operator<<(std::ostream &os, const Animal &animal) {
	return (os << animal.getType());
}