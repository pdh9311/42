#include "Karen.hpp"
#include <unistd.h>
#include <ctime>

int main(void)
{
	Karen karen;
	int random;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	while (1) {
		random = static_cast<double>(std::rand()) / RAND_MAX * 4;
		karen.complain(Karen::COMMENTS[random]);
		usleep(500 * 1000);
	}

	return (0);
}
