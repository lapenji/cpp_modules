#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Cat* j = new Cat();
	const Dog* i = new Dog();
	delete j;//should not create a leak
	delete i;

	return 0;
}
