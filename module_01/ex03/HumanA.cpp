#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){
	std::cout << "Ho creato un HumanA con nome " << this->name << " e arma " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "ciao sono " << this->name << "e ora muoio" << std::endl;
}

void	HumanA::attack(void) {
	if (this->weapon.getType() != "")
		std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	else
		std::cout << this->name << " attacks with their mani nude" << std::endl;
}
