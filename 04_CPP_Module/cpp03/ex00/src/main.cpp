#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct("ABC");
	ct.toString();

	ct.attack("XYZ");
	ct.toString();

	ct.takeDamage(10);
	ct.toString();

	ct.beRepaired(10);
	ct.toString();

	ct.takeDamage(5);
	ct.toString();

	ct.takeDamage(8);
	ct.toString();

	ct.beRepaired(3);
	ct.toString();

	ct.beRepaired(4);
	ct.toString();

	ct.beRepaired(5);
	ct.toString();

	return (0);
}