#include <iostream>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
private:
	std::string name;
public:
	void setName(std::string nameToBeSet);
	void announce(void);
	void deleteZombie(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif