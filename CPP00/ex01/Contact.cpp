#include "Contact.hpp"

std::string Contact::getNonEmptyInput(const std::string message)
{
	std::string input;
	bool success = false;

	std::cout << message;
	while (!success)
	{
		std::getline(std::cin, input);
		success = !input.empty();
		if (!success)
			std::cout << "Empty field. " << message;
	}
	return input;
}

std::string Contact::truncateString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::printBasicInfo()
{
	std::cout << "|" << std::setw(10) << truncateString(firstName) << "|" << std::setw(10) << truncateString(lastName) << "|" << std::setw(10) << truncateString(nickName) << '\n';
}

void Contact::printAllInfo()
{
	std::cout << "First name: " << firstName << '\n';
	std::cout << "Last name: " << lastName << '\n';
	std::cout << "Nickname: " << nickName << '\n';
	std::cout << "Phone number: " << phoneNumber << '\n';
	std::cout << "The darkest secret: " << darkestSecret << '\n';
}

void Contact::addOneContact()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	firstName = getNonEmptyInput("Enter their first name: ");
	lastName = getNonEmptyInput("Enter their last name: ");
	nickName = getNonEmptyInput("Enter their nickname: ");
	phoneNumber = getNonEmptyInput("Enter their phone number: ");
	darkestSecret = getNonEmptyInput("Enter their darkest secret: ");

	exists = true;
}