#pragma once

#include <stdio.h>
#include <stdlib.h>

template <class T>
class Array
{
private:
	T *array;
	int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array & other);
	Array operator=(const Array & other);
	~Array();

	T& operator[](int index);
	int size();

	class OutOfBoundsException : public std::exception
	{
	private:
		int value;
	public:
		OutOfBoundsException(int val);
		const char* what() const throw();
		int getValue() const;
	};
};