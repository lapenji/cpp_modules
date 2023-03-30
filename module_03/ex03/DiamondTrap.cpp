#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";

	FragTrap::hitP = 100;
	ScavTrap::energyP = 50;
	FragTrap::attackD = 30;

	std::cout << "DiamondTrap name " << this->name << " created!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond trap named " << this->name << " destroyed!" << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My diamond name is " << this->name << " my claptrap name is " << this->ClapTrap::name << std::endl;
}
