#include "Weapon.hpp"

std::string Weapon::getType(void)
{
	return this->type;
}

void Weapon::setType(std::string name)
{
	this->type = name;
}

Weapon::Weapon(std::string name)
{
	this->setType(name);
}
