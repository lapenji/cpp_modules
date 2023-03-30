#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->attackD = 30;
	this->hitP = 100;
	this->energyP = 100;
	std::cout << "FragTrap named " << this->name << " constructed!" << std::endl;

}

FragTrap::~FragTrap() {
	std::cout << "FragTrap named " << this->name << " destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(toCopy) {
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = toCopy;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->attackD = rhs.attackD;
		this->energyP = rhs.energyP;
		this->hitP = rhs.hitP;
	}
	return (*this);
}

void	FragTrap::attack(const std::string &target) {
	if (this->energyP > 0 && this->hitP > 0) {
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackD << " points of damage" << std::endl;
		this->energyP --;
	}
	else if (this->energyP == 0) {
		std::cout << "FragTrap " << this->name << " can't attack cause it's out of energy point :(" << std::endl;
	}
	else if (this->hitP <= 0) {
		std::cout << "FragTrap " << this->name << " can't attack cause is dead" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap named " << this->name << " high fives everybody!" << std::endl;
}
