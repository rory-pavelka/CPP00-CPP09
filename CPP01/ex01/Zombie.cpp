#include "Zombie.hpp"

void Zombie::setName(std::string nameToBeSet)
{
	name = nameToBeSet;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::deleteZombie(void)
{
	std::cout << "Deleting " << this->name << "\n";
	delete(this);
}

void Zombie::deleteHorde(void)
{
	std::cout << "Deleting " << this->name << "\n";
	delete [] this;
}
