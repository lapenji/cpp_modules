#include "Animal.hpp"

class Cat : public Animal {

	public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &toCopy);
	Cat &operator=(const Cat &rhs);

	void makeSound() const;
};
