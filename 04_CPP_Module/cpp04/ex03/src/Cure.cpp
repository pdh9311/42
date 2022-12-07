#include "Cure.hpp"
# include "ICharacter.hpp"

Cure::Cure() : AMateria("cure", false) {
	std::cout << "[Cure] default constructure" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria() {
	*this = cure;
	std::cout << "[Cure] copy constructure" << std::endl;
}

Cure::~Cure() {
	std::cout << "[Cure] Destructure" << std::endl;
}

Cure& Cure::operator=(const Cure &cure) {
	this->type_ = cure.getType();
	this->isEquipped_ = cure.getIsEquipped();
	return (*this);
}

AMateria* Cure::clone() const {
	std::cout << "[Cure::clone()]" << std::endl;
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << C_GREEN << "* heals " << target.getName() << "'s wounds *" << C_NC << std::endl;
}
