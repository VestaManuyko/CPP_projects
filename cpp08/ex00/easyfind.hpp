#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class notFound : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Not found.");
		}
};

template<typename T>
typename T::iterator easyfind(T &x, int value)
{
	typename T::iterator it = find(x.begin(), x.end(), value);
	if (it == x.end())
		throw notFound();
	return it;
}


#endif
