#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
    	Array() : _array(NULL), _size(0) {};
		Array(unsigned int n)
		{
			if (n == 0)
				return ;
			_array = new T[n]();
			_size = n;
		}
		Array(const Array& other)
		{
			delete[] _array;
			_size = other.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		Array& operator=(const Array& other)
		{
			delete[] _array;
			_size = other.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			return *this;
		}
		~Array()
		{
			delete[] _array;
		}

		unsigned int	size(void) const
		{
			return _size;
		}

		T& operator[](std::size_t i)
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");

			return _array[i];
		}

		const T& operator[](std::size_t i) const
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _array[i];
		}
};

#endif
