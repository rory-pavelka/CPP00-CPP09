#ifndef SCAVTRAP
#define SCAVTRAP

#include <iostream>
#include "ClapTrap.hpp"

#endif

class ScavTrap: public ClapTrap
{
private:
	bool gatekeeperMode;
public:
	ScavTrap();
	ScavTrap(const std::string _name);
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
};