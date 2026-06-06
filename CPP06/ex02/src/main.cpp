#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

Base* generate(void)
{
	srand(time(0));
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			std::cout << "Chose A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Chose B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Chose C" << std::endl;
			return (new C());
	}
	return NULL;
}

void identify(Base* p)
{
	A * aPtr = dynamic_cast<A*>(p);
	if (aPtr)
		std::cout << "Pointer identified as A" << std::endl;

	B * bPtr = dynamic_cast<B*>(p);
	if (bPtr)
		std::cout << "Pointer identified as B" << std::endl;

	C * cPtr = dynamic_cast<C*>(p);
	if (cPtr)
		std::cout << "Pointer identified as C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Reference identified as A" << std::endl;
	}
	catch (std::exception& e) {}

	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "Reference identified as B" << std::endl;
	}
	catch (std::exception& e) {}

	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "Reference identified as C" << std::endl;
	}
	catch (std::exception& e) {}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Base* test = generate();
		identify(test);
		identify(*test);
		std::cout << std::endl;
		delete test;
		usleep(1000000);
	}
}