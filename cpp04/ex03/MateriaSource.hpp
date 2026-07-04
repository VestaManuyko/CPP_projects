#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"

class MateriaSource
{
	private:
		AMateria	*_known[4];
		int			_slot;
	public:
    	MateriaSource();
		MateriaSource(const MateriaSource& other); 
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		void 		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

#endif
