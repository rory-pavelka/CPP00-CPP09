#include <iostream>

#ifndef WEAPON
#define WEAPON

class Weapon
{
private:
	std::string type;
public:
	std::string getType(void);
	void setType(std::string name);
	Weapon(std::string name);
};

#endif