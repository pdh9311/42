#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Color.hpp"

# define INVEN_SIZE 4

class Character : public ICharacter {
private:
	std::string name_;
	AMateria *materia_[INVEN_SIZE];

public:
	Character();
	Character(const std::string &name);
	Character(const Character &character);
	~Character();

	Character& operator=(const Character &character);

	const std::string& getName() const;
	const AMateria* getMateriaIdx(int idx) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif
