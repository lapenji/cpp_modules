#include "Serializer.hpp"

int	main() {
	Data	ptr;

	ptr.b = 1;
	ptr.c = 32;
	ptr.i2 = 12;
	ptr.i = 123;
	Serializer ciccio(&ptr);
	std::cout << ciccio.ptr << std::endl;
	std::cout << ciccio.serialize() << std::endl;
	std::cout << ciccio.deserialize() << std::endl;
}
