#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "  *** Dog default constructor ***\n";
	this->type = "dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog & other)
{
	std::cout << "  *** Dog copy constructor ***\n";
	this->type = other.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = other.brain->ideas[i];
}

Dog & Dog::operator=(const Dog & other)
{
	std::cout << "  *** Dog assignment operator ***\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	delete this->brain;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = other.brain->ideas[i];
	return *this;
}

Dog::~Dog()
{
	std::cout << "  *** Dog destructor ***\n";
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
