#include "Zombie.hpp"

int main(void)
{
	Zombie *z;
	int n = 5;

	std::cout << "Zombie 객체 배열 생성" << std::endl;
	z = Zombie::zombieHorde(n, "zombieHorde");
	std::cout << std::endl << z << " | " << &z[0] << std::endl << std::endl;
	delete[] z;
	return (0);
}