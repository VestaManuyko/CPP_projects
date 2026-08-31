#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T>
void iter(T *arr, const std::size_t &len, void(*f)(T &))
{
	if (arr == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}
template<typename T>
void iter(T *arr, const std::size_t &len, void(*f)(const T &))
{
	if (arr == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif
