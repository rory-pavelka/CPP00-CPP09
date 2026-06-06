#include <iostream>
#include "Weapon.hpp"

#ifndef HUMAN_A
#define HUMAN_A

class HumanA
{
private:
	Weapon &weapon;
	std::string name;
public:
	HumanA(std::string name, Weapon &weapon);
	void attack();
};

#endif