#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T> & other)
{
	if (other.array != NULL)
	{
		_size = other._size;
		array = new T[_size];
	}
	else
	{
		_size = 0;
		array = NULL;
	}
	for (int i = 0; i < _size; i++)
		array[i] = other.array[i];
}

template <typename T>
Array<T> Array<T>::operator=(const Array<T> & other)
{
	if (other.array != NULL)
	{
		_size = other._size;
		array = new T[_size];
	}
	else
	{
		_size = 0;
		array = NULL;
	}
	for (int i = 0; i < _size; i++)
		array[i] = other.array[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (array)
		delete[] array;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index >= _size || index < 0)
	{
		throw OutOfBoundsException(index);
	}
	return array[index];
}

template <typename T>
int Array<T>::size()
{
	return _size;
}

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(int val) :
value(val)
{}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bound";
}

template <typename T>
int Array<T>::OutOfBoundsException::getValue() const
{
	return value;
}
