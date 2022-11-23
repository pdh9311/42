#include "ScavTrap.hpp"

int main(void)
{
	std::cout << C_BLUE << " =============== ScavTrap member function Test Start =============== " << C_NC << std::endl;
	ScavTrap st("Scav1");
	st.toString();

	st.guardGate();

	st.attack("Other ScavTrap");
	st.toString();

	st.takeDamage(30);
	st.toString();

	st.beRepaired(3);
	st.toString();

	st.beRepaired(30);
	st.toString();

	std::cout << C_BLUE << " =============== ScavTrap member function Test End =============== " << C_BLUE << std::endl << std::endl;

	std::cout << C_BLUE << " =============== virtual(Destructor, toString) Test Start =============== " << C_BLUE << std::endl;
	ClapTrap *p_st = new ScavTrap("newScav");
	p_st->toString();
	delete p_st;
	std::cout << C_BLUE << " =============== virtual(Destructor, toString) Test End =============== " << C_BLUE << std::endl << std::endl;

	return (0);
}