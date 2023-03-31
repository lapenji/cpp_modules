#include "RPN.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Numero di argomenti sbagliato" << std::endl;
		exit (1);
	}
	std::string	operazione = argv[1];
	Rnp calculator(operazione);
}
