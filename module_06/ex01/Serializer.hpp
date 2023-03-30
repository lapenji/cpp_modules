#pragma once

#include <iostream>
#include <stdint.h>


struct Data {
	int		i;
	int		i2;
	char	c;
	bool	b;
};


class Serializer {
	private:
	Serializer();
	Serializer(const Serializer &toCopy);
	Serializer&operator=(const Serializer &rhs);
	public:
	Serializer(Data *ptr);
	~Serializer();
	uintptr_t	serialize();
	Data		*deserialize();
	Data		*ptr;
	uintptr_t	addr;
};
