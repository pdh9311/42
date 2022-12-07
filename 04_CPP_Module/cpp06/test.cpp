#include <iostream>

class MyFloat {
public:
	float real;
};

class MyInt {
public:
	int num;
	operator MyFloat(void) {
		MyFloat myFloat = {static_cast<float>(num)};
		return myFloat;
	}
};

int main(void)
{
	MyInt myInt = {5};
	MyFloat myFloat = {0.f};

	myFloat = static_cast<MyFloat>(myInt);

	std::cout << myFloat.real << std::endl;
	return 0;
}
