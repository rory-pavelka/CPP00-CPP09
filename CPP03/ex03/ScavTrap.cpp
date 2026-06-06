#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = _hitPoints;
	this->energyPoints = _energyPoints;
	this->attackDamage = _attackDamage;
	this->gatekeeperMode = false;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name)
{
	this->hitPoints = _hitPoints;
	this->energyPoints = _energyPoints;
	this->attackDamage = _attackDamage;
	this->gatekeeperMode = false;
	std::cout << "ScavTrap name constructor called\n";
}


ScavTrap::ScavTrap(const ScavTrap &other) :
ClapTrap(other)
{
	this->gatekeeperMode = other.gatekeeperMode;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called\n";
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout
		<< "ScavTrap "
		<< this->name
		<< " attacks "
		<< target
		<< ", causing "
		<< this->attackDamage
		<< " points of damage!"
		<< std::endl;
		this->energyPoints--;
	}
	else
	{
		if (this->hitPoints == 0)
		{
			std::cout
			<< "ScavTrap "
			<< this->name
			<< " is already dead!"
			<< std::endl;
		}
		if (this->energyPoints == 0)
		{
			std::cout
			<< "ScavTrap "
			<< this->name
			<< " doesn't have enough energy points!"
			<< std::endl;
		}
	}
}

void ScavTrap::guardGate()
{
	if (this->gatekeeperMode == false)
	{
		this->gatekeeperMode = true;
		std::cout
		<< "ScavTrap "
		<< this->name
		<< " is now in Gate keeper mode!"
		<< std::endl;
	}
	else
	{
		std::cout
		<< "ScavTrap "
		<< this->name
		<< " is already in Gate keeper mode!"
		<< std::endl;
	}
}
