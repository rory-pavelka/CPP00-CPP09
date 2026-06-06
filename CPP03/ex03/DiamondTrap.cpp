#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name")
{
	this->name = "Default";
	this->hitPoints = FragTrap::_hitPoints;
	this->energyPoints = ScavTrap::_hitPoints;
	this->attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string _name) : ClapTrap(_name + "_clap_name")
{
	this->name = _name;
	this->hitPoints = FragTrap::_hitPoints;
	this->energyPoints = ScavTrap::_energyPoints;
	this->attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap name constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	this->name = other.name;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	this->name = other.name;
	std::cout << "DiamondTrap copy assignment operator called\n";
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap:" << std::endl << "My name is " << this->name << " and my ClapTrap's name is " << ClapTrap::name << std::endl;
}
