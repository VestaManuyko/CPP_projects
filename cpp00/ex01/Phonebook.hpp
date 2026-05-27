#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();

	void	AddContact(Contact *Contact);
	void	DisplayContacts();

	private:
		int		AmountOfContacts;
		Contact *contacts[8];
};

#endif