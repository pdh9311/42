#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type_ = "WrongCat";
	std::cout << C_PURPLE << "WrongCat " << C_GREEN << " Default Constructor" << C_NC << std::endl;
}

WrongCat::WrongCat(const WrongCat &wCat) {
	*this = wCat;
	std::cout << C_PURPLE << "WrongCat " << C_GREEN << " Copy Constructor" << C_NC << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << C_PURPLE << "WrongCat " << C_RED << " Destructor" << C_NC << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &wCat) {
	this->type_ = wCat.getType();
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "meow!" << std::endl;
}