#pragma once

#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>

class ScalarConverter {
	private:
	char		c;
	int			n;
	float		f;
	double		d;
	bool		isPossibleInt;
	std::string	str;
	std::string	type;
	public:
	ScalarConverter();
	bool		isLiteral();
	char		getC();
	int			getN();
	float		getF();
	double		getD();
	bool		getBo();
	std::string	getType();
	std::string	getStr();
	void		setC(char c);
	void		setN(int n);
	void		setF(float f);
	void		setD(double d);
	void		setStr(std::string str);
	bool		isChar();
	bool		isInt();
	bool		isDouble();
	bool		isFloat();
	void		setType();
	void		convert();
	void		printAll();
};
