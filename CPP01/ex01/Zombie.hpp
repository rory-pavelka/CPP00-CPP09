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
	void deleteHorde(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif