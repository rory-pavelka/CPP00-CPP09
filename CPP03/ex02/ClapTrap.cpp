#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string _name) :
name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) :
name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this == &other)
    	return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout
		<< "ClapTrap "
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
			<< "ClapTrap "
			<< this->name
			<< " is already dead!"
			<< std::endl;
		}
		if (this->energyPoints == 0)
		{
			std::cout
			<< "ClapTrap "
			<< this->name
			<< " doesn't have enough energy points!"
			<< std::endl;
		}
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		return;

	if (this->hitPoints == 0)
	{
		std::cout
		<< "ClapTrap "
		<< this->name
		<< " is already dead, they can't be hurt more!"
		<< std::endl;
	}
	else if (this->hitPoints >= amount)
	{
		std::cout
		<< "ClapTrap "
		<< this->name
		<< " takes "
		<< amount
		<< " points of damage!"
		<< std::endl;
		this->hitPoints -= amount;
	}
	else
	{
		std::cout
		<< "ClapTrap "
		<< this->name
		<< " takes "
		<< this->hitPoints
		<< " points of damage!"
		<< std::endl;
		this->hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount == 0)
		return;

	if (this->hitPoints == 0)
	{
		std::cout
		<< "ClapTrap "
		<< this->name
		<< " is already dead, they can't regenerate HPs!"
		<< std::endl;
	}
	else if (this->energyPoints > 0)
	{
		std::cout
		<< "ClapTrap "
		<< this->name
		<< " repairs "
		<< amount
		<< " points of damage!"
		<< std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
	{
		std::cout
		<< "ClapTrap "
		<< this->name
		<< " doesn't have enough energy points!"
		<< std::endl;
	}
}

void ClapTrap::printStats()
{
	std::cout << std::endl;
	return; // comment this line to print stats
	std::cout
	<< "  \\/ stats \\/"
	<< std::endl
	<< this->name << "    hit points count: "
	<< this->hitPoints
	<< std::endl
	<< this->name << " energy points count: "
	<< this->energyPoints
	<< std::endl
	<< this->name << "       attack damage: "
	<< this->attackDamage
	<< std::endl
	<< "  /\\ stats /\\"
	<< std::endl
	<< std::endl;
}
