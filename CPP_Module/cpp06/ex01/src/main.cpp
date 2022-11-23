#include "Data.hpp"

int main(void)
{
	Data d1;
	std::cout << &d1 << std::endl;

	uintptr_t uip = serialize(&d1);
	std::cout << uip << std::endl;

	Data *d2 = deserialize(uip);
	std::cout << d2 << std::endl;

	return (0);
}
