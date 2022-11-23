#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << std::setfill('-') << std::setw(40) << "\n";
	const WrongAnimal *wMeta = new WrongAnimal();
	const WrongAnimal *wi = new WrongCat();
	wMeta->makeSound();
	wi->makeSound();
	delete wMeta;
	delete wi;

	return (0);
}