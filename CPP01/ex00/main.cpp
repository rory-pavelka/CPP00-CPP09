#include "Zombie.hpp"

int main(void)
{
	Zombie* z1;
	Zombie* z2;

	randomChump("test random 1");
	z1 = newZombie("test new 1");
	z2 = newZombie("test new 2");
	randomChump("test random 2");
	z1->announce();
	z2->announce();
	z1->deleteZombie();
	z2->deleteZombie();
	randomChump("test random 3");
}
