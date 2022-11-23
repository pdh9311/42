#include "Character.hpp"

Character::Character() :name_("") {
	for (int i = 0; i < INVEN_SIZE; i++) {
		this->materia_[i] = NULL;
	}
	std::cout << "[Character] " << C_PURPLE << this->name_ << C_NC << " default constructure" << std::endl;
}

Character::Character(const std::string &name) : name_(name) {
	for (int i = 0; i < INVEN_SIZE; i++) {
		this->materia_[i] = NULL;
	}
	std::cout << "[Character] " << C_PURPLE << this->name_ << C_NC << " param(name) constructure" << std::endl;
}

Character::Character(const Character &character) {
	*this = character;
	std::cout << "[Character] copy constructure" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < INVEN_SIZE; i++) {
		delete this->materia_[i];
		this->materia_[i] = NULL;
	}
	std::cout << "[Character] " << C_PURPLE << this->name_ << C_NC << " Destructure" << std::endl;
}

Character& Character::operator=(const Character &character) {
	const AMateria *tmp;

	this->name_ = character.getName();
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->materia_[i] != NULL) {
			delete this->materia_[i];
			this->materia_[i] = NULL;
		}
		tmp = character.getMateriaIdx(i);
		if (tmp != NULL) {
			this->materia_[i] = tmp->clone();
		}
	}
	return (*this);
}

const std::string& Character::getName() const {
	return (this->name_);
}

const AMateria* Character::getMateriaIdx(int idx) const {
	return (this->materia_[idx]);
}

void Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->materia_[i] == NULL) {
			m->setIsEquipped(true);
			this->materia_[i] = m;
			std::cout << C_BLUE << this->name_ << " equipped " << m->getType() << C_NC << std::endl;
			return ;
		}
	}
	std::cout << C_RED << this->name_ << " Inventory is full!" << C_NC << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > INVEN_SIZE)
		return ;
	if (this->materia_[idx] != NULL) {
		if (this->materia_[idx]->getIsEquipped() == true) {
			this->materia_[idx]->setIsEquipped(false);
			std::cout << C_BLUE << this->name_ << " unequipped " << this->materia_[idx]->getType() << C_NC << std::endl;
		} else {
			std::cout << C_YELLOW << this->name_ << "already unequipped " << this->materia_[idx]->getType() << C_NC << std::endl;
		}
	} else {
		std::cout << C_RED << this->name_ << "Inventory materia[" << idx << "] empty" << C_NC << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > INVEN_SIZE)
		return ;
	if (this->materia_[idx] != NULL)
		this->materia_[idx]->use(target);
}
