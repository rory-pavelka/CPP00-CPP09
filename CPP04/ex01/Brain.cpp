#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "  *** Brain default constructor ***\n";
}

Brain::Brain(const Brain & other)
{
	std::cout << "  *** Brain copy constructor ***\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain Brain::operator=(const Brain & other)
{
	std::cout << "  *** Brain assignment operator ***\n";
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "  *** Brain destructor ***\n";
}