#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class Zombie {
private:
	std::string	name_;

	Zombie(const std::string name);

public:
	~Zombie();

	void				announce(void) const;
	static Zombie*		newZombie(std::string name);
	static void			randomChump(std::string name);
	static std::string	randomName(void);

};

#endif