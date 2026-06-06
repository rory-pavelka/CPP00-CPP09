#pragma once

template <typename T>
void iter(T *array, int const len, void(*function)(T &target))
{
	for (int i = 0; i < len; i++)
		function(array[i]);
}

template <typename T>
void iter(T *array, int const len, void(*function)(T const &target))
{
	for (int i = 0; i < len; i++)
		function(array[i]);
}
