#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string _name) : ClapTrap(_name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap name constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called\n";
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void)
{

	std::cout << "--- FragTrap: ---" << std::endl << "Okay, hold up — before we move on, I need a moment to properly acknowledge the sheer awesomeness that just happened. That was top-tier excellence, and I refuse to let it go uncelebrated. So, extend that hand of glory, raise it high, and let’s meet in midair for a triumphant, slow-motion-worthy high five of destiny!" << std::endl << "-----------------" << std::endl;
}
