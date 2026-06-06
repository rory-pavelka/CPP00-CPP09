#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	std::string prompt;
	PhoneBook phonebook;

	phonebook.initContactExists();
	while (1)
	{
		std::cout << "Enter a command: ADD | SEARCH | EXIT :\n";
		std::cin >> prompt;
		if (prompt == "ADD")
			phonebook.addContact();
		else if (prompt == "SEARCH")
			phonebook.searchContact();
		else if (prompt == "EXIT")
			break ;
	}
}
