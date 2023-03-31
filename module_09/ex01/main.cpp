#include "RPN.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Just one argument, the RPN operation in one string" << std::endl;
		exit (1);
	}
	std::string	operazione = argv[1];
	Rnp calculator(operazione);
}
