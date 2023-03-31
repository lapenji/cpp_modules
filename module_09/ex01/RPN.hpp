#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class Rnp {
	private:
	Rnp();
	std::stack<int>	pila;
	public:
	Rnp(std::string& operazione);
	bool	isOperator(char c);
	int		multi(int a, int b);
	int		addi(int a, int b);
	int		divi(int a, int b);
	int		sottra(int a, int b);

};


#endif
