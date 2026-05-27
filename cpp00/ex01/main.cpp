#include <cctype>
#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::string str;
	Contact		Contact;
	ContactData Data;

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
			if (Contact.GetContactData(&Data) == 1)
			{
				std::cout << "\nEOF detected, exiting...\n";
				return 0;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
