#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of parameters :(" << std::endl;
	}
	else {
		ScalarConverter	ciccio;
		ciccio.setStr(argv[1]);
		ciccio.convert();
	}
	return 0;
}
