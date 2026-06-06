#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "  *** Animal default constructor ***\n";
	this->type = "";
}

Animal::Animal(const Animal & other)
{
	std::cout << "  *** Animal copy constructor ***\n";
	this->type = other.type;
}

Animal & Animal::operator=(const Animal & other)
{
	std::cout << "  *** Animal assignment operator ***\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "  *** Animal destructor ***\n";
}

void Animal::makeSound() const
{
	std::cout << "no_sound" << std::endl;
}
