#ifndef ARRAY_HPP
# define ARRAY_HPP

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
			try
			{
				_array = new T[n];
				for (unsigned int i = 0; i < n; i++)
					_array[i] = 0;
				_size = n;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		Array(const Array& other);
		{
			delete[] _array;
			try
			{
				_size = other.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		Array& operator=(const Array& other)
		{
			delete[] _array;
			try
			{
				_size = other.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		~Array()
		{
			delete[] _array;
		}

		unsigned int	size(void) const
		{
			return _size;
		}
};

#endif
