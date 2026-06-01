#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
    	Zombie(std::string myName);
		~Zombie();

	void announce( void );

	private:
		std::string name;
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif
