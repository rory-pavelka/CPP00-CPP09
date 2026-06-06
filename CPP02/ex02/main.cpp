#include "Fixed.hpp"

int main(void)
{
/*	std::cout << (Fixed(1.5f) + Fixed(4)) << std::endl;
	std::cout << (Fixed(22.25f) * Fixed(4)) << std::endl;
	std::cout << (Fixed(100000000000000.0f) / Fixed(3.0f)) << std::endl;
	std::cout << (Fixed(5.05f) - Fixed(2.01f)) << std::endl;
*/
	Fixed a;

	std::cout << "a = " << a << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl << std::endl;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "max(a,b) = " << Fixed::max( a, b ) << std::endl << std::endl;
	for (int i = 0; i < 5000; i++)
		a++;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "max(a,b) = " << Fixed::max( a, b ) << std::endl << std::endl;


	std::cout << (Fixed(3.25f) + Fixed(5.5f)) << std::endl;
	std::cout << (Fixed(6.5f) * Fixed(2.5f)) << std::endl;
	std::cout << (Fixed(8.75f) / Fixed(2.5f)) << std::endl;
	std::cout << (Fixed(5.5f) - Fixed(2.125f)) << std::endl;

	return 0;
}