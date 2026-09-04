#ifndef ARRAY_HPP
# define ARRAY_HPP

class Array
{
	public:
    	Array();
		Array(const Array& other); 
		Array& operator=(const Array& other);
		~Array();
};

#endif
