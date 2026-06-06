#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include "ClapTrap.hpp"

#endif

class FragTrap: virtual public ClapTrap
{
protected:
	static const int _hitPoints = 100;
	static const int _energyPoints = 100;
	static const int _attackDamage = 30;
public:
	FragTrap();
	FragTrap(const std::string _name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();
	void highFivesGuys(void);
};