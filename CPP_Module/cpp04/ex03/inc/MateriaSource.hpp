#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *materia_[INVEN_SIZE];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &materiaSource);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource &materiaSource);

	const AMateria* getMateriaIdx(int idx) const;

	void learnMateria(AMateria* materia);
	AMateria* createMateria(const std::string &type);
};