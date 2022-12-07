#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie *z = new Zombie[N];

	std::cout << std::endl;
	for (int i = 0; i < N; i++) {
		z[i].setName(name);
	}
	return (z);
}