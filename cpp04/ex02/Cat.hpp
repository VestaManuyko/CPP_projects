#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
    	Cat();
		Cat(const Cat& other); 
		Cat& operator=(const Cat& other);
		~Cat();

	void makeSound() const;
	void setIdea(int index, std::string idea);
	const std::string &getIdea(int index) const;

	private:
		Brain	*_brain;
};

#endif
