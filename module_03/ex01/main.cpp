#include "ScavTrap.hpp"

int	main() {
	ScavTrap ciccio("ciccio");
	ciccio.attack("mostro");
	ciccio.beRepaired(1);
	ciccio.takeDamage(1);
	ciccio.guardGate();
}
