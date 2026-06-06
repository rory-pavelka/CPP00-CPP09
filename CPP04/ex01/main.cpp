#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void tempAnimals()
{
	Cat cat1;
	std::cout << std::endl;
	Cat cat2(cat1);
	std::cout << std::endl;
	cat1 = cat2;
	std::cout << std::endl;
	Dog dog1;
	std::cout << std::endl;
	Dog dog2(dog1);
	std::cout << std::endl;
	dog1 = dog2;
	std::cout << std::endl;
}

int main(void)
{
	tempAnimals();
	std::cout << std::endl;

	Animal *array[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	for (int i = 0; i < 6; i++)
	{
		delete array[i];
	}
}
