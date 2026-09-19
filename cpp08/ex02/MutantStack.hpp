#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
	public:
	MutantStack() : std::stack<T, container>() {}
	MutantStack(const MutantStack& other) : std::stack<T, container>(other) {}
	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T, container>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	typedef typename container::iterator iterator;
	typedef typename container::const_iterator const_iterator;
	typedef typename container::reverse_iterator reverse_iterator;
	typedef typename container::const_reverse_iterator const_reverse_iterator;

	typename container::iterator begin()
	{
		return this->c.begin();
	}

	typename container::iterator end()
	{
		return this->c.end();
	}

	typename container::const_iterator begin() const
	{
		return this->c.begin();
	}

	typename container::const_iterator end() const
	{
		return this->c.end();
	}

	typename container::reverse_iterator rbegin()
	{
		return this->c.rbegin();
	};

	typename container::reverse_iterator rend()
	{
		return this->c.rend();
	};

	typename container::const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	};

	typename container::const_reverse_iterator rend() const
	{
		return this->c.rend();
	};
};

#endif
