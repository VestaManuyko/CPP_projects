#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook(void)
{
	int	i = 0;
	while (i < 8)
		this->contacts[i++] = NULL;
	this->AmountOfContacts = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void Phonebook::AddContact(Contact *Contact, int i)
{
	if (this->AmountOfContacts < 8)
	{
		this->contacts[this->AmountOfContacts] = Contact;
		this->AmountOfContacts += 1;
	}
	else
	{
		this->contacts[i] = Contact;
	}
}

static std::string	CheckData(std::string str)
{
	if (str.length() > 10)
		str = str .substr(0, 9) + '.';
	return (str);
}

void Phonebook::DisplayContacts(void)
{
	ContactData Data;
	int	i = 0;

	while (i < this->AmountOfContacts)
	{
		this->contacts[i]->GetContactData(&Data);
		std::cout << "|" << std::setw(10) << i << "|"
			<< std::setw(10) << CheckData(Data.FirstName) << "|"
			<< std::setw(10) << CheckData(Data.LastName) << "|"
			<< std::setw(10) << CheckData(Data.Nickname) << "|" << std::endl;
		i++;
	}
}
