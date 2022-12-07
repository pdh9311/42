#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type_ = "WrongAnimal";
	std::cout << C_AQUA << "WrongAnimal " << C_GREEN << "Default Constructor" << C_NC << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &wAnimal) {
	*this = wAnimal;
	std::cout << C_AQUA << "WrongAnimal " << C_GREEN << "Copy Constructor" << C_NC << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << C_AQUA << "WrongAnimal " << C_RED << "Destructor" << C_NC << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wAnimal) {
	this->type_ = wAnimal.getType();
	return (*this);
}

std::string WrongAnimal::getType(void) const {
	return (this->type_);
}

void WrongAnimal::setType(const std::string &type) {
	this->type_ = type;
}

void WrongAnimal::makeSound() const {
	std::cout << "I just WrongAnimal, I can't sound yet!" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const WrongAnimal &wAnimal) {
	return (os << wAnimal.getType());
}