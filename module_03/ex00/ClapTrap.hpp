#pragma once
#include <iostream>

class ClapTrap {
	private :
	std::string name;
	unsigned int	hitP;
	unsigned int	energyP;
	unsigned int	attackD;
	public :
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &toCopy);
	ClapTrap &operator=(const ClapTrap &rhs);
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};
