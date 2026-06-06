#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void tempScavTrap()
{
	ScavTrap test1;
	ScavTrap test2("name");
	ScavTrap test3(test1);
	test3 = test2;
	std::cout << std::endl;
}

int main(void)
{
	tempScavTrap();
	std::cout << std::endl;
	ScavTrap test("OurScavTrap");

	test.printStats();
	test.attack("Oponent");
	test.printStats();
	test.takeDamage(20);
	test.printStats();
	test.beRepaired(50);
	test.printStats();
	test.takeDamage(80);
	test.printStats();
	test.takeDamage(49);
	test.printStats();
	test.beRepaired(20);
	test.printStats();
	test.takeDamage(21);
	test.printStats();
	test.beRepaired(20);
	test.printStats();
	test.takeDamage(1);
	test.printStats();

	test.guardGate();
	test.guardGate();
	test.guardGate();

	return 0;
}
