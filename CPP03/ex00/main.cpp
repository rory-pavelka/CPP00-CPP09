#include "ClapTrap.hpp"

void tempClapTrap()
{
	ClapTrap test1;
	ClapTrap test2("name");
	ClapTrap test3(test1);
	test3 = test2;
	std::cout << std::endl;
}

int main(void)
{
	tempClapTrap();
	std::cout << std::endl;

	ClapTrap test("OurClapTrap");

	test.printStats();
	test.attack("Trap");
	test.printStats();
	test.takeDamage(5);
	test.printStats();
	test.beRepaired(3);
	test.printStats();
	test.takeDamage(20);
	test.printStats();
	test.takeDamage(1);
	test.printStats();
	test.beRepaired(20);
	test.printStats();
	test.takeDamage(1);
	test.printStats();

	return 0;
}
