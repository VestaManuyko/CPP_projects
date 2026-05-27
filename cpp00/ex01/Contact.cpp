#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int Contact::FillContactData()
{
	std::string	str;

	std::cout << "To add a contact you need to provide contact details\nPlease enter first name: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: first name.\nPlease enter first name: ";
	}
	this->Data.FirstName = str;
	std::cout << "Please enter last name: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: last name.\nPlease enter last name: ";
	}
	this->Data.LastName = str;
	std::cout << "Please enter nickname: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: nickname.\nPlease enter nickname: ";
	}
	this->Data.Nickname = str;
	std::cout << "Please enter phone number: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: phone number.\nPlease enter phone number: ";
	}
	this->Data.PhoneNumber = str;
	std::cout << "Please enter their darkest secret: ";
	while (1)
	{
		if (!std::getline(std::cin, str))
			return 1;
		if (!str.empty())
			break ;
		std::cout << "No information entered for contact field: their darkest secret.\nPlease enter their darkest secret: ";
	}
	this->Data.DarkestSecret = str;
	return 0;
}

void	Contact::GetContactData(ContactData *Data)
{
	Data->FirstName = this->Data.FirstName;
	Data->LastName = this->Data.LastName;
	Data->Nickname = this->Data.Nickname;
	Data->PhoneNumber = this->Data.PhoneNumber;
	Data->DarkestSecret = this->Data.DarkestSecret;
}
