#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# define FRAGTRAP_HP 100
# define FRAGTRAP_EP 100
# define FRAGTRAP_AD 30

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &fragTrap);
	~FragTrap();

	FragTrap& operator=(const FragTrap &fragTrap);

	void highFivesGuys(void);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void toString();
};

#endif