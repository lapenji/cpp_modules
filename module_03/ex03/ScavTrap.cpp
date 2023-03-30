#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitP = 100;
	this->energyP = 50;
	this->attackD = 20;
	std::cout << "ScavTrap named " << this->name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap named " << this->name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy) {
	std::cout << "ScavTrap copy constructor called!" << std::endl;
	*this = toCopy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->attackD = rhs.attackD;
		this->energyP = rhs.energyP;
		this->hitP = rhs.hitP;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	if (this->energyP > 0 && this->hitP > 0) {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackD << " points of damage" << std::endl;
		this->energyP --;
	}
	else if (this->energyP == 0) {
		std::cout << "ScavTrap " << this->name << " can't attack cause it's out of energy point :(" << std::endl;
	}
	else if (this->hitP <= 0) {
		std::cout << "ScavTrap " << this->name << " can't attack cause is dead" << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->name << " is now in gate keeper mode!" << std::endl;
}
