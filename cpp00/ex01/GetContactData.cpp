#include "Contact.hpp"
#include <cctype>

int Contact::GetContactData()
{
	std::string	str;

	std::cout << "Adding a contact...no information yet\nPlease enter first name: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: first name.\nPlease enter first name: ";
	}
	this->data.FirstName = str;
	std::cout << "Please enter last name: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: last name.\nPlease enter last name: ";
	}
	this->data.LastName = str;
	std::cout << "Please enter nickname: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: nickname.\nPlease enter nickname: ";
	}
	this->data.Nickname = str;
	std::cout << "Please enter phone number: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: phone number.\nPlease enter phone number: ";
	}
	this->data.PhoneNumber = str;
	std::cout << "Please enter their darkest secret: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: their darkest secret.\nPlease enter their darkest secret: ";
	}
	this->data.DarkestSecret = str;
	return 0;
}
