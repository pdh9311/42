#include "Base.hpp"
#include "A.hpp"
#include <iomanip>

class Parent {
	std::string s;
public:
	Parent() : s("Parent") {}
	virtual ~Parent() {}
	void toString() {
		std::cout << s << std::endl;
	}
};

class Child : public Parent {
	std::string s;
public:
	Child() : s("Child") {}
	void toString() {
		std::cout << s << std::endl;
	}
};

// derived -> base -> derieved (O)
void test1() {
	A a;
	Base *basePtr = &a;
	A *aptr = dynamic_cast<A*>(basePtr);
	if (aptr == NULL)
		std::cout << "aptr is NULL" << std::endl;
	else
		std::cout << "aptr is not NULL" << std::endl;
	std::cout << std::setw(50) << std::setfill('-') << '\n';
}

// base -> derived (X)
void test2() {
	Base base;
	Base *basePtr = &base;
	A *aptr = dynamic_cast<A*>(basePtr);
	if (aptr == NULL)
		std::cout << "aptr is NULL" << std::endl;
	else
		std::cout << "aptr is not NULL" << std::endl;
	std::cout << std::setw(50) << std::setfill('-') << '\n';
}

// derived -> base -> derieved (O)
void test3() {
	Child child;
	Parent *parentPtr = &child;
	Child *childPtr = dynamic_cast<Child*>(parentPtr);
	if (childPtr == NULL)
		std::cout << "childPtr is NULL" << std::endl;
	else
		std::cout << "childPtr is not NULL" << std::endl;
	childPtr->toString();
	std::cout << std::setw(50) << std::setfill('-') << '\n';
}

// base -> derived (X)
void test4() {
	Parent parent;
	Parent *parentPtr = &parent;
	Child *childPtr = dynamic_cast<Child*>(parentPtr);
	if (childPtr == NULL)
		std::cout << "childPtr is NULL" << std::endl;
	else
		std::cout << "childPtr is not NULL" << std::endl;
	childPtr->toString();
	std::cout << std::setw(50) << std::setfill('-') << '\n';
}

int main(void)
{
	std::cout << "[dynamic_cast Test]" << std::endl;
	std::cout << std::setw(50) << std::setfill('-') << '\n';
	test1();
	test2();
	test3();
	test4();
	return (0);
}
