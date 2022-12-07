#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int random = rand() % 3;
	switch(random) {
		case 0:
			std::cout << "Generate A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generate B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Generate C" << std::endl;
			return (new C());
	}
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A class" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B class" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C class" << std::endl;
}

void identify(Base &p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A class" << std::endl;
	} catch(...) {
		try {
			B b = dynamic_cast<B&>(p);
			std::cout << "B class" << std::endl;
		} catch(...) {
			C c = dynamic_cast<C&>(p);
			std::cout << "C class" << std::endl;
		}
	}
}
