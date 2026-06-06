#include <iostream>
#include "Weapon.hpp"

#ifndef HUMAN_B
#define HUMAN_B

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(std::string name);
	void attack();
	void setWeapon(Weapon *weapon);
};

#endif