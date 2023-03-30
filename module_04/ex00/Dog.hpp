#include "Animal.hpp"

class Dog: public Animal {

	public:
	Dog(void);
	~Dog(void);
	Dog(const Dog &toCopy);
	Dog &operator=(const Dog &rhs);
	void makeSound() const;
};
