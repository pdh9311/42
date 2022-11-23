#include "Dog.hpp"

Dog::Dog() : Animal(), brain_(NULL) {
	this->type_ = "Dog";
	this->brain_ = new Brain();
	std::cout << C_YELLOW << "Dog " << C_GREEN << "Default Constructor" << C_NC << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(), brain_(NULL) {
	*this = dog;
	std::cout << C_YELLOW << "Dog " << C_GREEN << "Copy Constructor" << C_NC << std::endl;
}

Dog::~Dog() {
	delete this->brain_;
	std::cout << C_YELLOW << "Dog " << C_RED << "Destructor" << C_NC << std::endl;
}

Dog& Dog::operator=(const Dog &dog) {
	if (this->brain_ != NULL) {
		delete (this->brain_);
		this->brain_ = NULL;
	}
	this->type_ = dog.getType();
	this->brain_ = new Brain(*dog.brain_);
	return (*this);
}

Brain* Dog::getBrain() const {
	return (this->brain_);
}

void Dog::makeSound() const {
	std::cout << "woof-woof!" << std::endl;
}
