#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << C_BLUE << " =============== DiamondTrap member function Test Start =============== " << C_NC << std::endl;
	DiamondTrap dt("Diamond1");
	dt.toString();

	dt.whoAmI();
	dt.guardGate();
	dt.highFivesGuys();

	dt.attack("Other DiamondTrap");
	dt.toString();

	dt.takeDamage(30);
	dt.toString();

	dt.beRepaired(3);
	dt.toString();

	dt.beRepaired(30);
	dt.toString();

	std::cout << C_BLUE << " =============== DiamondTrap member function Test End =============== " << C_BLUE << std::endl << std::endl;

	std::cout << C_BLUE << " =============== virtual(Destructor, toString) Test Start =============== " << C_BLUE << std::endl;
	ClapTrap *p_ft = new DiamondTrap("newFrag");
	p_ft->toString();
	delete p_ft;
	std::cout << C_BLUE << " =============== virtual(Destructor, toString) Test End =============== " << C_BLUE << std::endl << std::endl;

	// /* polymorphism */
	// ClapTrap **arr = new ClapTrap*[10];
	// arr[0] = new ScavTrap("scav1");
	// arr[1] = new ScavTrap("scav2");
	// arr[2] = new ScavTrap("scav3");
	// arr[3] = new ScavTrap("scav4");
	// arr[4] = new ScavTrap("scav5");
	// arr[5] = new FragTrap("frag1");
	// arr[6] = new FragTrap("frag2");
	// arr[7] = new FragTrap("frag3");
	// arr[8] = new DiamondTrap("diamond1");
	// arr[9] = new DiamondTrap("diamond2");
	// for (int i = 0; i < 10; i++)
	// 	arr[i]->toString();

	// for (int i = 0; i < 10; i++)
	// 	delete arr[i];
	// delete[] arr;

	return (0);
}
