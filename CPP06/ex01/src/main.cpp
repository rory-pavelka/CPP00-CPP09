#include "Serializer.hpp"

int main()
{
	Data d;
	d.s = "This string should stay the same after the conversion.";
	d.i = 42;

	std::cout
	<< "1st pointer: " << &d
	<< "\n1st string : " << d.s
	<< "\n1st number : " << d.i
	<< std::endl << std::endl;

	uintptr_t temp = Serializer::serialize(&d);
	Data *result = Serializer::deserialize(temp);

	std::cout
	<< "2nd pointer: " << result
	<< "\n2nd string : " << result->s
	<< "\n2nd number : " << result->i
	<< std::endl;
}
