#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# define SCAVTRAP_HP 100
# define SCAVTRAP_EP 50
# define SCAVTRAP_AD 20

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap &scavTrap);

	void guardGate();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void toString();
};

#endif