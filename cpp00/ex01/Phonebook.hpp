#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();

	void	AddContact(Contact *Contact, int i);
	void	DisplayContacts();
	int		AmountOfContacts;

	private:
		Contact *contacts[8];
};

#endif