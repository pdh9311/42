#include "Cat.hpp"

Cat::Cat() {
	this->type_ = "Cat";
	std::cout << C_PURPLE << "Cat " << C_GREEN << " Default Constructor" << C_NC << std::endl;
}

Cat::Cat(const Cat &cat) {
	*this = cat;
	std::cout << C_PURPLE << "Cat " << C_GREEN << " Copy Constructor" << C_NC << std::endl;
}

Cat::~Cat() {
	std::cout << C_PURPLE << "Cat " << C_RED << " Destructor" << C_NC << std::endl;
}

Cat& Cat::operator=(const Cat &cat) {
	this->type_ = cat.getType();
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "meow!" << std::endl;
}