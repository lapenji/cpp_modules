#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
	std::string	name;
	AMateria	*Inventory[4];
	public:
	Character();
	Character(std::string name);
	Character( const Character & toCopy);
	~Character();
	Character &operator= (const Character &rhs);
	std::string const & getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};
