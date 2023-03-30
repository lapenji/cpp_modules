#include "FragTrap.hpp"

int	main() {
	FragTrap ciccio("ciccio");
	FragTrap mostro = ciccio;
	ciccio.attack("mostro");
	mostro.attack("ciccio");
	ciccio.takeDamage(1);
	ciccio.beRepaired(1);
	ciccio.highFivesGuys();
}
