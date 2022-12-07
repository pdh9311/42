#include "Dog.hpp"
#include "Cat.hpp"


int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::cout << "[ Default Test ]" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	std::cout << "\n[ Utilize polymorphism Test ]" << std::endl;
	Animal **animal = new Animal*[6];

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 6; i++) {
		animal[i]->makeSound();
	}

	for (int i = 0; i < 6; i++) {
		delete animal[i];
	}
	delete[] animal;

	std::cout << "\n[ Deep copy Test ]" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	for (int i = 0; i < 5; i++) {
		std::cout << dog1.getBrain()->getIdeasIdx(i) << std::endl;
	}
	std::cout << dog1.getBrain() << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << dog2.getBrain()->getIdeasIdx(i) << std::endl;
	}
	std::cout << dog2.getBrain() << std::endl << std::endl;

	dog1.getBrain()->setIdeasIdx("test", 0);
	std::cout << dog1.getBrain()->getIdeasIdx(0) << std::endl;
	std::cout << dog2.getBrain()->getIdeasIdx(0) << std::endl;

	return (0);
}
