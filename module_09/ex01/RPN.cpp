#include "RPN.hpp"

Rnp::Rnp(std::string& operazione) {
	for (int i = 0; i < (int)operazione.length(); i++) {
		if (isdigit(operazione[i])) {
			this->pila.push(int(operazione[i]) - '0');
		}
		else if (isOperator(operazione[i])) {
			int a;
			int b;
			a = this->pila.top();
			this->pila.pop();
			b = this->pila.top();
			this->pila.pop();
			switch (operazione[i]) {
				case '*' :
					std::cout << operazione[i] << a << " " << b << std::endl;
					pila.push(multi(a, b));
					break;
				case '+' :
					std::cout << operazione[i] << a << " " << b << std::endl;
					pila.push(addi(a, b));
					break;
				case '-' :
					std::cout << operazione[i] << a << " " << b << std::endl;
					pila.push(sottra(a, b));
					break;
				case '/' :
					std::cout << operazione[i] << a << " " << b << std::endl;
					pila.push(divi(a, b));
					break;
			}
		}
		else if (operazione[i] != ' ') {
			std::cout << "Wrong char! ==> " << operazione[i] << std::endl;
			exit(1);
		}
	}
	std::cout << "il risultato di [" << operazione << "] è " << pila.top() << std::endl;
}

int	Rnp::addi(int a, int b) {
	return (a + b);
}

int Rnp::multi(int a, int b) {
	return (a * b);
}

int		Rnp::divi(int a, int b) {
	return (b / a);
}

int		Rnp::sottra(int a, int b) {
	return (b - a);
}

bool	Rnp::isOperator(char c) {
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return true;
	return false;
}

