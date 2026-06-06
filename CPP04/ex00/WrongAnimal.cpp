#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "  *** WrongAnimal default constructor ***\n";
	this->type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal & other)
{
	std::cout << "  *** WrongAnimal copy constructor ***\n";
	this->type = other.type;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & other)
{
	std::cout << "  *** WrongAnimal assignment operator ***\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "  *** WrongAnimal destructor ***\n";
}

void WrongAnimal::makeSound() const
{
	std::cout
	<< "wrong_no_sound"
	<< std::endl;
}
