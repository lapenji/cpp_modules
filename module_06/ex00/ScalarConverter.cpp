#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	this->c = '\0';
	this->n = 0;
	this->f = 0.0f;
	this->d = 0.0;
	this->type = "";
	this->isPossibleInt = true;
}

char	ScalarConverter::getC() {
	return this->c;
}

int		ScalarConverter::getN() {
	return this->n;
}

float	ScalarConverter::getF() {
	return this->f;
}

double	ScalarConverter::getD() {
	return this->d;
}

std::string	ScalarConverter::getStr() {
	return this->str;
}

std::string	ScalarConverter::getType() {
	return this->type;
}

void	ScalarConverter::setC(char c) {
	this->c = c;
}
void	ScalarConverter::setN(int n) {
	this->n = n;
}
void	ScalarConverter::setF(float f) {
	this->f = f;
}
void	ScalarConverter::setD(double d) {
	this->d = d;
}

void	ScalarConverter::setStr(std::string str) {
	this->str = str;
}

bool	ScalarConverter::isLiteral() {
	if (this->str.compare("nan") == 0 || this->str.compare("nanf") == 0
	 || this->str.compare("+inf") == 0 || this->str.compare("+inff") == 0
	 || this->str.compare("-inf") == 0 || this->str.compare("-inff") == 0)
		return (true);
	else
		return (false);
}

bool	ScalarConverter::isChar() {
	if (this->str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]))
		return true;
	return false;
}

bool	ScalarConverter::isInt() {
	int	i;

	i = 1;
	if (this->str[0] != '-' && this->str[0] != '+' && !std::isdigit(this->str[0])) {
		return false;
	}
	if ((this->str[0] == '-' || this->str[0] == '+') && this->str[1] == '\0')
		return false;
	while (this->str[i]) {
		if (!std::isdigit(this->str[i]))
			return false;
		i++;
	}
	return true;
}

bool	ScalarConverter::isDouble() {
	int	i;
	int	punti;

	i = 1;
	punti = 0;
	if (this->str[0] != '-' && this->str[0] != '+' && !std::isdigit(this->str[0])) {
		return false;
	}
	if (this->str[1] == '.' && !std::isdigit(this->str[0]))
		return false;
	if ((this->str[0] == '-' || this->str[0] == '+') && this->str[1] == '\0')
		return false;
	while (this->str[i]) {
		if (!std::isdigit(this->str[i]) && this->str[i] != '.')
			return false;
		if (this->str[i] == '.') {
			punti++;
		}
		i++;
	}
	if (punti == 1 && this->str[this->str.length() - 1] != '.')
		return (true);
	else
		return (false);
}

bool	ScalarConverter::isFloat() {
	size_t	i;
	int	punti;

	i = 1;
	punti = 0;
	if (this->str[0] != '-' && this->str[0] != '+' && !std::isdigit(this->str[0])) {
		return false;
	}
	if (this->str[1] == '.' && !std::isdigit(this->str[0]))
		return false;
	if ((this->str[0] == '-' || this->str[0] == '+') && this->str[1] == '\0')
		return false;
	while (i < this->str.length() - 1) {
		if (!std::isdigit(this->str[i]) && this->str[i] != '.')
			return false;
		if (this->str[i] == '.') {
			punti++;
		}
		i++;
	}
	if (punti == 1 && this->str[this->str.length() - 1] == 'f' && this->str[this->str.length() - 2] != '.')
		return (true);
	else
		return (false);
}

void	ScalarConverter::setType() {
	if (isChar())
		this->type = "CHAR";
	else if (isInt())
		this->type = "INT";
	else if (isDouble())
		this->type = "DOUBLE";
	else if (isFloat())
		this->type = "FLOAT";
	else if (isLiteral())
		this->type = "LITERALS";
	else
		this->type = "NONE";
}

void	ScalarConverter::printAll() {
	if (this->type != "LITERALS" && this->type != "NONE") {
		if (this->c > 31 && this->c < 127)
			std::cout << "char: " << this->c << std::endl;
		else if (this->c < 32 && this->c >= 0)
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: Impossible" << std::endl;
		if (this->isPossibleInt == true)
			std::cout << "int: " << this->n << std::endl;
		else
			std::cout << "int: Impossible" << std::endl;
		std::cout << "double: " << this->d;
		if (this->d - this->n == 0 && this->d <= 999999)
			std::cout << ".0";
		std::cout << std::endl;
		std::cout << "float: " << this->f;
		if (this->f - this->n == 0 && this->f <= 999999)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else if (this->type == "LITERALS") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		if (this->str == "nan" || this->str == "nanf") {
			std::cout << "double: nan" << std::endl;
			std::cout << "float: nanf" << std::endl;
		}
		else if (this->str == "-inff" || this->str == "-inf") {
			std::cout << "double: -inf" << std::endl;
			std::cout << "float: -inff" << std::endl;
		}
		else if (this->str == "+inff" || this->str == "+inf") {
			std::cout << "double: +inf" << std::endl;
			std::cout << "float: +inff" << std::endl;
		}
	}
	else {
		std::cout << "ERROR: Not a valid input!" << std::endl;
	}
}

void	ScalarConverter::convert() {
	setType();
	if (this->type == "CHAR") {
		this->c = this->str[0];
		this->n = static_cast<int>(this->c);
		this->d = static_cast<double>(this->c);
		this->f = static_cast<float>(this->c);
	}
	else if (this->type == "INT") {
		long	tmp;
		tmp = std::atol(this->str.c_str());
		if (tmp > 2147483647 || tmp < -2147483648) {
			this->isPossibleInt = false;
		}
		else
			this->n = std::atoi(this->str.c_str());
		if (this->n > 126 || this->isPossibleInt == false || this->n < 0) {
			this->c = 130;
		}
		else
			this->c = static_cast<char>(this->n);
		this->f = std::atof(this->str.c_str());
		this->d = static_cast<double>(this->f);
	}
	else if (this->type == "DOUBLE") {
		this->d = std::atof(this->str.c_str());
		if (this->d > 2147483647 || this->d < -2147483648) {
			this->isPossibleInt = false;
		}
		else
			this->n = static_cast<int>(this->d);
		if (this->d > 126) {
			this->c = 130;
		}
		else
			this->c = static_cast<char>(this->n);
		this->f = static_cast<float>(this->d);
	}
	else if (this->type == "FLOAT") {
		this->f = std::atof(this->str.c_str());
		if (this->f > 2147483647 || this->f < -2147483648) {
			this->isPossibleInt = false;
		}
		else
			this->n = static_cast<int>(this->f);
		if (this->f > 126) {
			this->c = 130;
		}
		else
			this->c = static_cast<char>(this->n);
		this->d = static_cast<double>(this->f);
	}
	printAll();
}
