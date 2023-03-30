#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
	firstName = "";
	lastName = "";
	phoneNbr = "";
	darkestSecret = "";
	nickName = "";
	index = 0;
}

Contact::Contact(string fname, string lname, string pNbr, string nName, string darkSec, int idx) {
	firstName = fname;
	lastName = lname;
	phoneNbr = pNbr;
	darkestSecret = darkSec;
	nickName = nName;
	index = idx;
}

string	Contact::getName() {
	return firstName;
}
string	Contact::getLast() {
	return lastName;
}
string	Contact::getNick() {
	return nickName;
}
int		Contact::getIndex() {
	return index;
}
void	Contact::printContact() {
	cout << "here is contact at index " << index << "\n\n";
	cout << firstName << "\n" << lastName << "\n" << nickName << "\n" << phoneNbr << "\n" << darkestSecret << "\n\n";
}

int	main(){
	PhoneBook rubrica;
	while (1) {
		rubrica.main_menu();
	}
}
