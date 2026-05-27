#include <cctype>
#include <iostream>
#include "phonebook.hpp"
#include "contact.hpp"

int main(void)
{
	std::string str;
	Contact		contact;
	ContactData data;

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
			std::cout << "Adding a contact...no information yet\nPlease enter first name: ";
			while (1)
			{
				if (!std::getline(std::cin, str))
				{
					std::cout << "\nEOF detected, exiting...\n";
					return 0;
				}
				if (!str.empty())
					break ;
				std::cout << "No information entered for contact field: first name.\nPlease enter first name: ";
			}
			data.FirstName = str;
			std::cout << "Please enter last name: ";
			while (1)
			{
				if (!std::getline(std::cin, str))
				{
					std::cout << "\nEOF detected, exiting...\n";
					return 0;
				}
				if (!str.empty())
					break ;
				std::cout << "No information entered for contact field: last name.\nPlease enter last name: ";
			}
			data.LastName = str;
			std::cout << "Please enter nickname: ";
			while (1)
			{
				if (!std::getline(std::cin, str))
				{
					std::cout << "\nEOF detected, exiting...\n";
					return 0;
				}
				if (!str.empty())
					break ;
				std::cout << "No information entered for contact field: nickname.\nPlease enter nickname: ";
			}
			data.Nickname = str;
			std::cout << "Please enter phone number: ";
			while (1)
			{
				if (!std::getline(std::cin, str))
				{
					std::cout << "\nEOF detected, exiting...\n";
					return 0;
				}
				if (!str.empty())
					break ;
				std::cout << "No information entered for contact field: phone number.\nPlease enter phone number: ";
			}
			data.PhoneNumber = str;
			std::cout << "Please enter their darkest secret: ";
			while (1)
			{
				if (!std::getline(std::cin, str))
				{
					std::cout << "\nEOF detected, exiting...\n";
					return 0;
				}
				if (!str.empty())
					break ;
				std::cout << "No information entered for contact field: their darkest secret.\nPlease enter their darkest secret: ";
			}
			data.DarkestSecret = str;
		}
		std::cout << std::endl;
	}
	return 0;
}
