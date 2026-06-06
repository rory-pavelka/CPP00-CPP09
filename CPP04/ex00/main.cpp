#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void tempAnimals()
{
	Cat cat1;
	Cat cat2(cat1);
	cat1 = cat2;
	std::cout << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	dog1 = dog2;
	std::cout << std::endl;
	Animal animal1;
	Animal animal2(animal1);
	animal1 = animal2;
	std::cout << std::endl;
}

int main(void)
{
	tempAnimals();
	std::cout << std::endl;
	Animal *cat = new Cat();
	Animal *dog = new Dog();
	Animal *animal = new Animal();
	std::cout << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	std::cout << std::endl;
	delete cat;
	delete dog;
	delete animal;
	std::cout << std::endl;
	WrongAnimal *wcat = new WrongCat();
	WrongAnimal *wanimal = new WrongAnimal();
	std::cout << std::endl;
	wcat->makeSound();
	wanimal->makeSound();
	std::cout << std::endl;
	delete wcat;
	delete wanimal;
}