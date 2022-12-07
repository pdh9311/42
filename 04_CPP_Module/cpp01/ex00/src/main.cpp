#include "Zombie.hpp"

int main(void)
{
	int		n = 3;
	Zombie	*z1;
	Zombie	*z2;
	Zombie	*z3;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::cout << "(Heap) Zombie object's create" << std::endl;
	z1 = Zombie::newZombie("Zombie1");
	z2 = Zombie::newZombie("Zombie2");
	z3 = Zombie::newZombie("Zombie3");
	std::cout << std::endl;

	std::cout << "(Stack) Zombie object's create & delete" << std::endl;
	for (int i = 0; i < n; i++)
		Zombie::randomChump(Zombie::randomName());
	std::cout << std::endl;

	std::cout << "(Heap) Zombie object's delete" << std::endl;
	delete z1;
	delete z2;
	delete z3;

	return (0);
}