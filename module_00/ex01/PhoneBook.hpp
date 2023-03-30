#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include <string>
using namespace std;

class PhoneBook {
	int	currentIdx;
	Contact 	lista[8];
	public:
	PhoneBook(){
		currentIdx = 0;
	}
	void	createContact();
	void	add_contact(Contact newContact);
	void	display_contact(int idx);
	void	display_search();
	void	choose_after_search();
	void	main_menu();
};
