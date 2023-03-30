#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
using namespace std;

class Contact {
	string	firstName;
	string	lastName;
	string	phoneNbr;
	string	darkestSecret;
	string	nickName;
	int		index;
	public:
	Contact();
	Contact(string fname, string lname, string pNbr, string nName, string darkSec, int idx);
	string	getName();
	string	getLast();
	string	getNick();
	int		getIndex();
	void	printContact();
};

#endif
