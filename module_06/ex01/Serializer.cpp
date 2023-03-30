#include "Serializer.hpp"

Serializer::Serializer(Data *ptr) {
	this->ptr = ptr;
	this->addr = reinterpret_cast<uintptr_t>(this->ptr);
}

Serializer::~Serializer() {
	std::cout << "Destructor called!" << std::endl;
}

uintptr_t	Serializer::serialize() {
	return (reinterpret_cast<uintptr_t>(this->ptr));
}

Data		*Serializer::deserialize() {
	return (reinterpret_cast<Data *>(this->addr));
}
