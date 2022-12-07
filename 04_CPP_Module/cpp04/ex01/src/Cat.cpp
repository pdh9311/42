#include "Cat.hpp"

Cat::Cat() : Animal(), brain_(NULL) {
	this->type_ = "Cat";
	this->brain_ = new Brain();
	std::cout << C_PURPLE << "Cat " << C_GREEN << " Default Constructor" << C_NC << std::endl;
}

Cat::Cat(const Cat &Cat) : Animal(), brain_(NULL) {
	*this = Cat;
	std::cout << C_PURPLE << "Cat " << C_GREEN << " Copy Constructor" << C_NC << std::endl;
}

Cat::~Cat() {
	delete this->brain_;
	std::cout << C_PURPLE << "Cat " << C_RED << " Destructor" << C_NC << std::endl;
}

Cat& Cat::operator=(const Cat &Cat) {
	if (this->brain_ != NULL) {
		delete (this->brain_);
		this->brain_ = NULL;
	}
	this->type_ = Cat.getType();
	this->brain_ = new Brain(*Cat.brain_);
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "meow!" << std::endl;
}
