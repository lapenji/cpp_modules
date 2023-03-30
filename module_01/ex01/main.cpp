#include "Zombie.hpp"

int	main() {
	std::cout << "creo orda di 7 zombie" << std::endl;
	Zombie *horde = zombieHorde(7, "pippo");
	for (int i = 0; i < 7; i++) {
		horde[i].announce();
	}
	std::cout << "ora cancello tutto" << std::endl;
	delete [] horde;
}
