#include "Dog.hpp"

Dog::Dog() {
	this->type_ = "Dog";
	std::cout << C_YELLOW << "Dog " << C_GREEN << "Default Constructor" << C_NC << std::endl;
}

Dog::Dog(const Dog &dog) {
	*this = dog;
	std::cout << C_YELLOW << "Dog " << C_GREEN << "Copy Constructor" << C_NC << std::endl;
}

Dog::~Dog() {
	std::cout << C_YELLOW << "Dog " << C_RED << "Destructor" << C_NC << std::endl;
}

Dog& Dog::operator=(const Dog &dog) {
	this->type_ = dog.getType();
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "woof-woof!" << std::endl;
}