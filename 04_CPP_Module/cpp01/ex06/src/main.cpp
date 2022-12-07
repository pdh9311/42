#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "./karenFilter [DEBUG / INFO / WARNING / ERROR]" << std::endl;
		std::cout << "./karenFilter [anything]" << std::endl;
		return (0);
	}

	Karen karen;
	std::string s(argv[1]);

	karen.filter(s);
	return (0);
}
