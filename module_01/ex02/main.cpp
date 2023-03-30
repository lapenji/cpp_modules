#include <iostream>

int	main() {
	std::string stringa = "HI THIS IS BRAIN";
	std::string *puntatore = &stringa;
	std::string &referenza = stringa;

	std::cout << &stringa << " <-- indirizzo memoria " << stringa << " <-- contenuto" << std::endl;
	std::cout << puntatore << " <-- indirizzo memoria " << *puntatore << " <-- contenuto" << std::endl;
	std::cout << &referenza << " <-- indirizzo memoria " << referenza << " <-- contenuto" << std::endl;
}

