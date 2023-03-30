#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat &toCopy);
	WrongCat &operator=(const WrongCat &rhs);
	void makeSound() const;
};
