#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include "ClapTrap.hpp"

#endif

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string _name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();
	void highFivesGuys(void);
};