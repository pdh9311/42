#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class Zombie {
private:
	std::string name_;

	Zombie();

public:
	~Zombie();

	void setName(const std::string name);

	void announce(void) const;

	static Zombie* zombieHorde(int N, std::string name);
};

#endif