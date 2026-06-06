#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void tempFragTrap()
{
	FragTrap test1;
	FragTrap test2("name");
	FragTrap test3(test1);
	test3 = test2;
	std::cout << std::endl;
}

int main(void)
{
	tempFragTrap();
	std::cout << std::endl;

	FragTrap test("OurFragTrap");

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

	test.highFivesGuys();

	return 0;
}
