#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include "ClapTrap.hpp"

#endif

class ScavTrap: virtual public ClapTrap
{
private:
	bool gatekeeperMode;
protected:
	static const int _hitPoints = 100;
	static const int _energyPoints = 50;
	static const int _attackDamage = 20;
public:
	ScavTrap();
	ScavTrap(const std::string _name);
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
};