#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class IMateriaSource
{
	public:
    	IMateriaSource();
		IMateriaSource(const IMateriaSource& other); 
		IMateriaSource& operator=(const IMateriaSource& other);
		~IMateriaSource();
};

#endif
