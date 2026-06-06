#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#endif

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const std::string _name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();
	void whoAmI();
	void attack(const std::string& target);
};