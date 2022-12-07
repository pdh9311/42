#include "Zombie.hpp"

void	Zombie::randomChump(std::string name) {
	Zombie	randZombie(name);
}

std::string	Zombie::randomName(void) {
	const std::string	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
	const int			nameLength = 6;
	const int			max = alphabet.length();
	const int			min = 0;
	int					random;

	std::string randName(nameLength, '\0');
	for (std::string::iterator iter = randName.begin(); iter != randName.end(); ++iter) {
		random = static_cast<double>(std::rand()) / RAND_MAX * (max - min) + min;
		*iter = alphabet.at(random);
	}
	return (randName);
}