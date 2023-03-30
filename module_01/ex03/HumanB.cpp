#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	this->weapon = NULL;
	std::cout << "Ho creato un HumanB con nome " << this->name << std::endl;
}

HumanB::~HumanB() {
	std::cout << "ciao sono " << this->name << "e ora muoio" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}


void	HumanB::attack(void) {
	if (this->weapon != NULL && this->weapon->getType() != "")
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their mani nude" << std::endl;
}
