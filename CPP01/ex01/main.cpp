#include "Zombie.hpp"

int main(void)
{
	Zombie* array;

	array = zombieHorde(6, "Test Horde");
	for (int i = 0; i < 6; i++)
	{
		array[i].announce();
	}
	array->deleteHorde();
	
}
