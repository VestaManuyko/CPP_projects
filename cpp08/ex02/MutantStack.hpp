#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
	public:

	typedef typename container::iterator iterator;

	typename container::iterator begin()
	{
		return this->c.begin();
	};

	typename container::iterator end()
	{
		return this->c.end();
	};
	typename container::const_iterator begin() const
	{
		return this->c.begin();
	};
	typename container::const_iterator end() const
	{
		return this->c.end();
	};
};

#endif
