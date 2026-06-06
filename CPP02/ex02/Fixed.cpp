#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
//	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int _value) : value(_value * (1 << this->bits))
{
//	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float _value) : value(roundf(_value * (1 << this->bits)))
{
//	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &obj) : value(obj.value)
{
//	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& c)
{
//	std::cout << "Copy assignment operator called\n";
	if (this != &c)
	{
		this->value = c.value;
	}
	return *this;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called\n";
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

bool Fixed::operator>(const Fixed& n) const
{
	return (this->value > n.value);
}

bool Fixed::operator<(const Fixed& n) const
{
	return (this->value < n.value);
}

bool Fixed::operator>=(const Fixed& n) const
{
	return !(this->value < n.value);
}

bool Fixed::operator<=(const Fixed& n) const
{
	return !(this->value > n.value);
}

bool Fixed::operator==(const Fixed& n) const
{
	return (this->value == n.value);
}

bool Fixed::operator!=(const Fixed& n) const
{
	return (this->value != n.value);
}

Fixed Fixed::operator+(const Fixed& n) const
{
	Fixed res;
	res.value = this->value + n.value;
	return (res);
}

Fixed Fixed::operator-(const Fixed& n) const
{
	Fixed res;
	res.value = this->value - n.value;
	return (res);
}

Fixed Fixed::operator*(const Fixed& n) const
{
	Fixed res;
	res.value = (this->value * n.value) >> this->bits;
	return (res);
}

Fixed Fixed::operator/(const Fixed& n) const
{
	Fixed res;
	res.value = ((this->value << this->bits) / (n.value));
	return (res);
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp;
	temp = *this;
	this->value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp;
	temp = *this;
	this->value--;
	return temp;
}

Fixed& Fixed::min(Fixed& c1, Fixed& c2)
{
	if (c1 < c2)
		return c1;
	else
		return c2;
}

const Fixed& Fixed::min(const Fixed& c1, const Fixed& c2)
{
	if (c1 < c2)
		return c1;
	else
		return c2;
}

Fixed& Fixed::max(Fixed& c1, Fixed& c2)
{
	if (c1 > c2)
		return c1;
	else
		return c2;
}

const Fixed& Fixed::max(const Fixed& c1, const Fixed& c2)
{
	if (c1 > c2)
		return c1;
	else
		return c2;
}
