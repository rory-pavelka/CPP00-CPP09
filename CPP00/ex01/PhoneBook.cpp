#include "PhoneBook.hpp"

void PhoneBook::initContactExists()
{
	for (int i = 0; i <= 7; i++)
	{
		contact[i].exists = false;
	}
}
void PhoneBook::addContact()
{
	int i;

	i = 0;
	while (contact[i].exists)
	{
		i++;
	}
	if (i == 8)
	{
		for (int j = 0; j < 7; j++)
		{
			contact[j] = contact[j + 1];
		}
		contact[7].addOneContact();
	}
	else
	{
		contact[i].addOneContact();
	}
}
void PhoneBook::searchContact()
{
	int index;
	int max_index;

	max_index = -1;
	for (int i = 0; i <= 7 && contact[i].exists; i++)
	{
		std::cout << std::setw(10) << i;
		contact[i].printBasicInfo();
		max_index = i;
	}
	std::cout << "Select index: ";
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (index > max_index || index < 0)
		std::cout << "Index out of range\n";
	else
		contact[index].printAllInfo();
}