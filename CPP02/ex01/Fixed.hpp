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
};

std::ostream& operator<<(std::ostream& os, const Fixed& c);
