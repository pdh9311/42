#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < INVEN_SIZE; i++) {
		this->materia_[i] = NULL;
	}
	std::cout << "[MateriaSource] default constructure" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	*this = materiaSource;
	std::cout << "[MateriaSource] copy constructure" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->materia_[i] != NULL)
			delete (this->materia_[i]);
	}
	std::cout << "[MateriaSource] Destructure" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materiaSource) {
	const AMateria *tmp;

	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->materia_[i] != NULL) {
			delete this->materia_[i];
			this->materia_[i] = NULL;
		}
		tmp =  materiaSource.getMateriaIdx(i);
		if (tmp != NULL)
			this->materia_[i] = tmp->clone();
	}
	return (*this);
}

const AMateria* MateriaSource::getMateriaIdx(int idx) const {
	return (this->materia_[idx]);
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (materia == NULL)
		return ;
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->materia_[i] == NULL) {
			this->materia_[i] = materia;
			std::cout << C_BLUE << "learned" << C_NC << std::endl;
			return ;
		}
	}
	std::cout << C_RED << "not learned, already is full!" << C_NC << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->materia_[i] != NULL && this->materia_[i]->getType() == type) {
			std::cout << C_BLUE << "created" << C_NC << std::endl;
			return (this->materia_[i]->clone());
		}
	}
	std::cout << C_RED << "not created" << C_NC << std::endl;
	return (NULL);
}
