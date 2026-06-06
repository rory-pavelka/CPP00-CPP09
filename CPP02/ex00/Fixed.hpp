#include <iostream>

class Fixed
{
private:
	long long int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed& c);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};