#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
T *easyfind(T &x, int value)
{
	T it = find(x.begin(), x.end(), value);
	if (it == x.end())
		return NULL;
	return it;
}

#endif
