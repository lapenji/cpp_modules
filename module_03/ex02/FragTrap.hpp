#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &toCopy);
	FragTrap &operator=(const FragTrap &rhs);
	void	attack(const std::string &target);
	void	highFivesGuys(void);
};
