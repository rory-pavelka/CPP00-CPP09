#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int index = 0;

	while (index < 4)
	{
		if (level == levels[index])
			break;
		index++;
	}

	switch (index)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			this->debug();
			std::cout << "\n";
		case 1:
			std::cout << "[ INFO ]\n";
			this->info();
			std::cout << "\n";
		case 2:
			std::cout << "[ WARNING ]\n";
			this->warning();
			std::cout << "\n";
		case 3:
			std::cout << "[ ERROR ]\n";
			this->error();
			std::cout << "\n";
			break;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}