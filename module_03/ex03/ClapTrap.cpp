#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitP(10), energyP(0), attackD(0) {
	std::cout << "Basic constructor called on ClapTrap named " << this->name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = toCopy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs){
		this->name = rhs.name;
		this->attackD = rhs.attackD;
		this->hitP = rhs.hitP;
		this->energyP = rhs.energyP;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->energyP > 0 && this->hitP > 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackD << " points of damage" << std::endl;
		this->energyP --;
	}
	else if (this->energyP == 0) {
		std::cout << "ClapTrap " << this->name << " can't attack cause it's out of energy point :(" << std::endl;
	}
	else if (this->hitP <= 0) {
		std::cout << "ClapTrap " << this->name << " can't attack cause is dead" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitP > amount) {
		std::cout << "ClapTrap " << this->name << " is attacked and lose " << amount << " hit points!" << std::endl;
		this->hitP -= amount;
		std::cout << "remaining hit points " << this->hitP << std::endl;
	}
	else {
		this->hitP -= amount;
		std::cout << "ClapTrap " << this->name << " dies!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyP > 0) {
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
		this->hitP += amount;
		this->energyP--;
		std::cout << "remaining hit points " << this->hitP << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name << "can't repair itself because is out of energy" << std::endl;
	}
}
