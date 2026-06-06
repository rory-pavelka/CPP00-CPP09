#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "  *** WrongCat default constructor ***\n";
	this->type = "wrong_cat";
}

WrongCat::WrongCat(const WrongCat & other)
{
	std::cout << "  *** WrongCat copy constructor ***\n";
	this->type = other.type;
}

WrongCat & WrongCat::operator=(const WrongCat & other)
{
	std::cout << "  *** WrongCat assignment operator ***\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "  *** WrongCat destructor ***\n";
}

void WrongCat::makeSound() const
{
	std::cout
	<< "wrong_meow"
	<< std::endl;
}