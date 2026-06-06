#include <iostream>
#include <limits>
#include <iomanip>
#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
private:
	Contact contact[8];

public:
	void initContactExists();
	void addContact();
	void searchContact();
};

#endif