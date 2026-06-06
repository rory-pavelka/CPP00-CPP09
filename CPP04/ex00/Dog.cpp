#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "  *** Dog default constructor ***\n";
	this->type = "dog";
}

Dog::Dog(const Dog & other)
{
	std::cout << "  *** Dog copy constructor ***\n";
	this->type = other.type;
}

Dog & Dog::operator=(const Dog & other)
{
	std::cout << "  *** Dog assignment operator ***\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "  *** Dog destructor ***\n";
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
