#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void printNewline()
{
	std::cout << std::endl;
}

void tempDiamondTrap()
{
	DiamondTrap test1;
	DiamondTrap test2("name");
	DiamondTrap test3(test1);
	test3 = test2;
	printNewline();
}

int main(void)
{
	tempDiamondTrap();
	printNewline();

	DiamondTrap test("OurDiamondTrap");

	test.printStats();

	test.attack("Oponent");

	printNewline();

	test.guardGate();
	test.guardGate();

	printNewline();

	test.highFivesGuys();

	printNewline();

	test.whoAmI();

	printNewline();

	return 0;
}
