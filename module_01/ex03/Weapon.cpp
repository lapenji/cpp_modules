#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
	std::cout << "sono la weapon type " << this->type << " e mi sto distruggendo" << std::endl;
}

std::string	Weapon::getType() {
	return this->type;
}

void		Weapon::setType(std::string type){
	this->type = type;
}
