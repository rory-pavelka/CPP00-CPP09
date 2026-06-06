#include <iostream>
#include <cmath>

class Fixed
{
private:
	long long int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const int _value);
	Fixed(const float _value);
	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed& c);
	~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator>(const Fixed&) const;
	bool operator<(const Fixed&) const;
	bool operator>=(const Fixed&) const;
	bool operator<=(const Fixed&) const;
	bool operator==(const Fixed&) const;
	bool operator!=(const Fixed&) const;

	Fixed operator+(const Fixed&) const;
	Fixed operator-(const Fixed&) const;
	Fixed operator*(const Fixed&) const;
	Fixed operator/(const Fixed&) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& c1, Fixed& c2);
	static const Fixed& min(const Fixed& c1, const Fixed& c2);
	static Fixed& max(Fixed& c1, Fixed& c2);
	static const Fixed& max(const Fixed& c1, const Fixed& c2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& c);
