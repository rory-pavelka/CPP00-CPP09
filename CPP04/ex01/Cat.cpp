#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "  *** Cat default constructor ***\n";
	this->type = "cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat & other)
{
	std::cout << "  *** Cat copy constructor ***\n";
	this->type = other.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = other.brain->ideas[i];
}

Cat & Cat::operator=(const Cat & other)
{
	std::cout << "  *** Cat assignment operator ***\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	delete this->brain;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = other.brain->ideas[i];
	return *this;
}

Cat::~Cat()
{
	std::cout << "  *** Cat destructor ***\n";
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
