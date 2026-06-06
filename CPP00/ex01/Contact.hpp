#include <iostream>
#include <limits>
#include <iomanip>

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string getNonEmptyInput(const std::string message);

public:
	bool exists;
	std::string truncateString(std::string str);
	void printBasicInfo();
	void printAllInfo();
	void addOneContact();
};

#endif
