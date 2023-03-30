#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
	std::string	name;
	public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	using	FragTrap::attack;
	void	whoAmI(void);
};
