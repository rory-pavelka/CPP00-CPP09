#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "  *** Cat default constructor ***\n";
	this->type = "cat";
}

Cat::Cat(const Cat & other)
{
	std::cout << "  *** Cat copy constructor ***\n";
	this->type = other.type;
}

Cat & Cat::operator=(const Cat & other)
{
	std::cout << "  *** Cat assignment operator ***\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "  *** Cat destructor ***\n";
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
