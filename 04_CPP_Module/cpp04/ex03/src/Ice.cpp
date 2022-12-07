#include "Ice.hpp"
# include "ICharacter.hpp"

Ice::Ice() : AMateria("ice", false) {
	std::cout << "[Ice] default constructure" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria() {
	*this = ice;
	std::cout << "[Ice] copy constructure" << std::endl;
}

Ice::~Ice() {
	std::cout << "[Ice] Destructure" << std::endl;
}

Ice& Ice::operator=(const Ice &ice) {
	this->type_ = ice.getType();
	this->isEquipped_ = ice.getIsEquipped();
	return (*this);
}

AMateria* Ice::clone() const {
	std::cout << "[Ice::clone()]" << std::endl;
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << C_AQUA << "* shoots an ice bolt at " << target.getName() << " *" << C_NC << std::endl;
}
