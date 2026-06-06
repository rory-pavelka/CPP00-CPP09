#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <iostream>

struct Data
{
	std::string s;
	int			i;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer & operator=(const Serializer &other);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
