#include "Harl.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Wrong number of parameters" << std::endl;
		return (1);
	}
	Harl	harl;
	int		i;
	i = 0;
	std::string livelli[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && livelli[i].compare(argv[1]))
		i++;
	switch (i) {
		case 0:
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 1:
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 2:
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "LIVELLO SBAGLIATO" << std::endl;
	}

}
