#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::string str;
	Contact		MyContact;
	Phonebook	MyPhonebook;

	while (1)
	{
		std::cout << "Choose a command from the following:\n1.)ADD\n2.)SEARCH\n3.)EXIT\nThe command chosen: ";
		if (!std::getline(std::cin, str))
		{
			std::cout << "EOF detected, cannot extract command, exiting...\n";
			return 0;
		}	
		if (str == "EXIT")
			return (0);
		if (str == "ADD")
		{
			if (MyContact.FillContactData() == 1)
			{
				std::cout << "\nEOF detected, exiting...\n";
				return 0;
			}
			MyPhonebook.AddContact(&MyContact);
		}
		if (str == "SEARCH")
		{
			std::cout << "|" << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
			MyPhonebook.DisplayContacts();
		}
		std::cout << std::endl;
	}
	return 0;
}
