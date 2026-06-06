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
	Cat cat;
	Dog dog;
//	Animal animal;
	std::cout << std::endl;
	cat.makeSound();
	dog.makeSound();
//	animal.makeSound();
	std::cout << std::endl;
}