#include "Character.hpp"

Character::Character() : name("Innominato"){
	for (int i = 0; i < 4; i ++) {
		this->Inventory[i] = NULL;
	}
	std::cout << "Empty constructor called for Character" << std::endl;
}

Character::Character(std::string name) : name(name){
	for (int i = 0; i < 4; i ++) {
		this->Inventory[i] = NULL;
	}
	std::cout << "Named constructor called for Character with name " << this->name << std::endl;
}

Character::Character( const Character &toCopy) {
	for (int i = 0; i < 4; i++) {
			delete this->Inventory[i];
	}
	*this = toCopy;
	std::cout << "Copy constructor called for Character" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->Inventory[i])
			delete this->Inventory[i];
	}
	std::cout << "Character destructor called!" << std::endl;
}

Character &Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			delete this->Inventory[i];
		}
		this->name = rhs.name;
		for (int i = 0; i < 4; i++) {
			this->Inventory[i] = rhs.Inventory[i];
		}
	}
	return (*this);
}

std::string const & Character::getName() const{
	return (this->name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->Inventory[i] == NULL) {
			this->Inventory[i] = m;
			std::cout << this->name << " added a materia to his inventory" << std::endl;
			return ;
		}
	}
	std::cout << this->name << "can not add materia to inventory" << std::endl;
}

void	Character::unequip(int idx) {
	if (this->Inventory[idx] != NULL) {
		delete this->Inventory[idx];
		this->Inventory[idx] = NULL;
		std::cout << this->name << " unequipped a materia at index " << idx << std::endl;
	}
	else {
		std::cout << this->name << " can not unequip!" << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (this->Inventory[idx]) {
		std::cout << "Character " << this->name;
		this->Inventory[idx]->use(target);
	}
	else {
		std::cout << "Character " << this->name << "can't use materia" << std::endl;
	}
}
