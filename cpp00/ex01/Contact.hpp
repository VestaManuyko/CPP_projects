#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "iostream"

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

	int	GetContactData();
	
	private:
		ContactData	data;
};

#endif