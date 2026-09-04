#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		T *_array;
		std::size_t _size;

	public:
    	Array() : _array(NULL), _size(0) {};
		Array(unsigned int n)
		{
			try
			{
				_array = new T[n];
				for (unsigned int i = 0; i < n; i++)
					_array[i] = 0;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array()
		{
			delete[] _array;
		}
};

#endif
