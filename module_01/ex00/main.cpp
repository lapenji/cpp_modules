#include "Zombie.hpp"

int	main() {
	std::cout << "creo zombie nello stack con randomChump" << std::endl;
	randomChump("ciccio");
	std::cout << "ora ne creo uno nello heap" << std::endl;
	Zombie *newZ = newZombie("mostro");
	newZ->announce();
	delete (newZ);
	return (0);
}
