#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
