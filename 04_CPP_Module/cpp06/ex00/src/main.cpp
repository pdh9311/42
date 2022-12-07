#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "./convert [value]" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++) {
		Convert c(argv[i]);
		c.printCovert();
		std::cout << std::endl;
	}

	return (0);
}
