#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name)
{}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}