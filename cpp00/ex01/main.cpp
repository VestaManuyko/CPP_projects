#include "Phonebook.hpp"
#include "Contact.hpp"
#include <sstream>

static int	DisplayContactDetails(std::string &str, Contact MyContacts[8], Phonebook MyPhonebook)
{
	ContactData Data;
	int 		index;

	while (1)
	{
		std::cout << "Please choose the index of the contact to display contact details.\nChosen index: ";
		if (!std::getline(std::cin, str))
		{
			std::cout << "EOF detected, exiting...\n";
			return 1;
		}
		if (str.length() == 1)
		{
			if (std::isdigit(str[0]))
			{
				std::istringstream(str) >> index;
				if (index < MyPhonebook.AmountOfContacts)
				{
					MyContacts[index].GetContactData(&Data);
					std::cout << "First name: " << Data.FirstName << std::endl;
					std::cout << "Last name: " << Data.LastName << std::endl;
					std::cout << "Nickname: " << Data.Nickname << std::endl;
					std::cout << "Phone number: " << Data.PhoneNumber << std::endl;
					std::cout << "Darkest secret: " << Data.DarkestSecret << std::endl;
					break ;
				}
			}
		}
		std::cout << "Incorrect index, try again\n";
	}
	return 0;
}

int main(void)
{
	std::string str;
	int			i = 0;
	Contact		MyContacts[8];
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
			if (i == 8)
				i = 0;
			if (MyContacts[i].FillContactData() == 1)
			{
				std::cout << "\nEOF detected, exiting...\n";
				return 0;
			}
			MyPhonebook.AddContact(&MyContacts[i], i);
			i++;
		}
		if (str == "SEARCH")
		{
			std::cout << "|" << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
			MyPhonebook.DisplayContacts();
			if (DisplayContactDetails(str,MyContacts, MyPhonebook) == 1)
				return 0;
		}
		std::cout << std::endl;
	}
	return 0;
}
