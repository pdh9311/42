#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << C_BLUE << " =============== FragTrap member function Test Start =============== " << C_NC << std::endl;
	FragTrap ft("Frag1");
	ft.toString();

	ft.highFivesGuys();

	ft.attack("Other FragTrap");
	ft.toString();

	ft.takeDamage(30);
	ft.toString();

	ft.beRepaired(3);
	ft.toString();

	ft.beRepaired(30);
	ft.toString();

	std::cout << C_BLUE << " =============== FragTrap member function Test End =============== " << C_BLUE << std::endl << std::endl;

	std::cout << C_BLUE << " =============== virtual(Destructor, toString) Test Start =============== " << C_BLUE << std::endl;
	ClapTrap *p_ft = new FragTrap("newFrag");
	p_ft->toString();
	delete p_ft;
	std::cout << C_BLUE << " =============== virtual(Destructor, toString) Test End =============== " << C_BLUE << std::endl << std::endl;

	return (0);
}