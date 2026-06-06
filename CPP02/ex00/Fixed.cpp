#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &obj) : value(obj.value)
{
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& c)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &c)
	{
		this->value = c.value;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	value = raw;
}
