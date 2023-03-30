#include "PhoneBook.hpp"

bool is_numeric(const std::string &s) {
	for (long unsigned int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

void	PhoneBook::display_search() {
	string	tmpName;
	string	tmpLast;
	string	tmpNick;

	for (int i = 0; i < 8; i++) {
		if (lista[i].getName() != "")
		{
			tmpName = lista[i].getName();
			tmpLast = lista[i].getLast();
			tmpNick = lista[i].getNick();
			if (tmpName.length() > 9)
			{
				tmpName[9] = '.';
				tmpName = tmpName.substr(0, 10);
			}
			if (tmpLast.length() > 9)
			{
				tmpLast[9] = '.';
				tmpLast = tmpLast.substr(0, 10);
			}
			if (tmpNick.length() > 9)
			{
				tmpNick[9] = '.';
				tmpNick = tmpNick.substr(0, 10);
			}
			cout << "|" << setw(10) << lista[i].getIndex();
			cout << "|" << setw(10) << tmpName;
			cout << "|" << setw(10) << tmpLast;
			cout << "|" << setw(10) << tmpNick;
			cout << "|";
			cout << "\n";
		}
	}
	choose_after_search();
}

void	PhoneBook::choose_after_search() {
	int	choice;
	string	tmp;
	choice = 9;

	if (lista[0].getName() == ""){
		cout << "You don't have any contact\n";
		return ;
	}
	while (choice >= 9 || choice < 0)
	{
		cout << "chose one index\n";
		getline(cin, tmp);
		choice = stoi(tmp);
		if (lista[choice].getLast() == "") {
			cout << "no contact at " << choice << " index, try again\n";
			choice = 9;
		}
	}
	lista[choice].printContact();
	return ;
}

void	PhoneBook::createContact(){
	string	name;
	string	lastName;
	string	phoneNbr;
	string	nickName;
	string	darkestSecret;
	Contact	newC;
	while (name == "")
	{
		cout << "Enter first name\n";
			getline(cin, name);
	}
	while (lastName == "")
	{
		cout << "Enter last name\n";
		getline(cin, lastName);
	}
	while (phoneNbr == "")
	{
		cout << "Enter phone number\n";
		getline(cin, phoneNbr);
		if (is_numeric(phoneNbr) == false)
		{
			phoneNbr = "";
			cout << "only numbers please, try again\n";
		}
	}
	while (nickName == "")
	{
		cout << "Enter nickname\n";
		getline(cin, nickName);
	}
	while (darkestSecret == "")
	{
		cout << "Enter darkest secret\n";
		getline(cin, darkestSecret);
	}

	newC = Contact(name, lastName, phoneNbr, nickName, darkestSecret, currentIdx);
	add_contact(newC);
}

void	PhoneBook::add_contact(Contact newContact) {
	lista[newContact.getIndex()] = newContact;
	if (currentIdx < 7)
		currentIdx ++;
	else
		currentIdx = 0;
}
void	PhoneBook::display_contact(int idx){
	lista[idx].printContact();
}

void	PhoneBook::main_menu() {
	string	choice;

	cout << "______________________________________\n";
	cout << "|                                    |\n";
	cout << "| 📞 WELCOME TO MY AWESOME PHONEBOOK |\n" ;
	cout << "|____________________________________|\n";
	cout << "|           |                        |\n";
	cout << "|       ADD | add a new contact      |\n";
	cout << "|           |                        |\n";
	cout << "|    SEARCH | search for contacts    |\n";
	cout << "|           |                        |\n";
	cout << "|      EXIT | close the program      |\n";
	cout << "|___________|________________________|\n\n\n";
	cout << "choose one:\n";
	while (choice != "ADD" && choice != "SEARCH" && choice != "EXIT") {
		getline(cin, choice);
		if (choice == "ADD")
			createContact();
		else if (choice == "SEARCH")
			display_search();
		else if (choice == "EXIT")
			exit(0);
		else
			cout << "wrong command, try again\n";
	}
}
