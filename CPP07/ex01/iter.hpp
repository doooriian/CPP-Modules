#pragma once
#include <string>

template<typename T, typename F>
void	iter(T *array, const int len, F function)
{
	if (array == NULL)
		return;
	for (int i = 0; i < len; i++)
		function(array[i]);
}

template<typename T, typename F>
void	iter(const T *array, const int len, F function)
{
	if (array == NULL)
		return;
	for (int i = 0; i < len; i++)
		function(array[i]);
}
