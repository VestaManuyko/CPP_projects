#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cctype>

struct ContactData
{
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;
};

class Contact
{
	public:
		Contact();
		~Contact();

	int		FillContactData();
	void	GetContactData(ContactData *Data);
	
	private:
		ContactData	Data;
};

#endif