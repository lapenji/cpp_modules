#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate() {
	int	n;

	n = std::rand() % 3;
	switch (n) {
		case 0 :
			std::cout << "making an A class" << std::endl;
			return new A;
		case 1 :
			std::cout << "making a B class" << std::endl;
			return new B;
		case 2 :
			std::cout << "making a C class" << std::endl;
			return new C;
	}
	std::cout << "No class generated, ERROR!" << std::endl;
	return NULL;
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "A class identified" << std::endl;
	}
	else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B class identified" << std::endl;
	}
	else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C class identified" << std::endl;
	}
	else
		std::cout << "Can not identify class :(" <<std::endl;
}

void	identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A class identified" << std::endl;
		(void)a;
	}
	catch (...) {}
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "B class identified" << std::endl;
		(void)b;
	}
	catch (...) {}
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "C class identified" << std::endl;
		(void)c;
	}
	catch (...) {}
}

int     main() {
	Base*	a = generate();
	Base*	b = generate();
	Base*	c = generate();
	Base*	d = new C;

	std::cout << "/* **************************************** */" << std::endl;

	std::cout << "a* = "; identify( a );
	std::cout << "a& = "; identify( *a ); std::cout << std::endl;

	std::cout << "b* = "; identify( b );
	std::cout << "b& = "; identify( *b ); std::cout << std::endl;

	std::cout << "c* = "; identify( c );
	std::cout << "c& = "; identify( *c ); std::cout << std::endl;

	std::cout << "d* = "; identify( d );
	std::cout << "d& = "; identify( *d ); std::cout << std::endl;

	std::cout << "/* ***************************************** */" << std::endl;


	delete a;
	delete b;
	delete c;
	delete d;

	return (0);
}
