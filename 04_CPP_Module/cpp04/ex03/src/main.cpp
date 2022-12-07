# include "Ice.hpp"
# include "Cure.hpp"
# include "Character.hpp"
# include "ICharacter.hpp"
# include "MateriaSource.hpp"

int main(void)
{
	AMateria *tmp;

	IMateriaSource* src = new MateriaSource();
	tmp = new Ice();
	std::cout << tmp << std::endl;
	src->learnMateria(tmp);
	tmp = new Cure();
	std::cout << tmp << std::endl;
	src->learnMateria(tmp);
	tmp = new Ice();
	std::cout << tmp << std::endl;
	src->learnMateria(tmp);
	tmp = new Cure();
	std::cout << tmp << std::endl;
	src->learnMateria(tmp);
	tmp = new Cure();
	std::cout << tmp << std::endl;
	src->learnMateria(tmp);
	delete tmp;
	tmp = NULL;

	ICharacter* me = new Character("me");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("pure");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}