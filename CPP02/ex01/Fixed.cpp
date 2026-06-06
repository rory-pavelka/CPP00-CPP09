#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int _value) : value(_value * (1 << this->bits))
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float _value) : value(roundf(_value * (1 << this->bits)))
{
	std::cout << "Float constructor called\n";
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

float Fixed::toFloat(void) const
{
	float result;

	result = (float)(value) / (float)(1 << this->bits);
	return result;
}

int Fixed::toInt(void) const
{
	int result;

	result = value / (1 << this->bits);
	return result;
}

std::ostream& operator<<(std::ostream& os, const Fixed& c)
{
	os << c.toFloat();
	return os;
}
