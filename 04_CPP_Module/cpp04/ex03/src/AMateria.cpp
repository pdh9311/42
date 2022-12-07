#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type_(""), isEquipped_(false) {
	std::cout << "[AMateria] default constructure" << std::endl;
}

AMateria::AMateria(const std::string &type) : type_(type), isEquipped_(false)  {
	std::cout << "[AMateria] param(type) constructure" << std::endl;
}

AMateria::AMateria(const std::string &type, bool isEquipped) : type_(type), isEquipped_(isEquipped) {
	std::cout << "[AMateria] param(type, isEquipped) constructure" << std::endl;
}

AMateria::AMateria(const AMateria &amateria) {
	*this = amateria;
	std::cout << "[AMateria] copy constructure" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "[AMateria] Destructure" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &amateria) {
	this->type_ = amateria.getType();
	this->isEquipped_ = amateria.getIsEquipped();
	return (*this);
}

const std::string& AMateria::getType() const {
	return (this->type_);
}

const bool& AMateria::getIsEquipped() const {
	return (this->isEquipped_);
}

void AMateria::setIsEquipped(bool is) {
	this->isEquipped_ = is;
}

void AMateria::use(ICharacter& target) {
	std::cout << "[AMateria::use] " << target.getName() << std::endl;
}
