#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &toCopy);
	ScavTrap &operator=(const ScavTrap &rhs);
	void	attack(const std::string &target);
	void	guardGate(void);
};
