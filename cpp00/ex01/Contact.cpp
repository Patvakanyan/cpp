#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string Lname, std::string Fname, std::string nick,
	std::string darkSecret, std::string number) : firstName(Fname),
	lastName(Lname), nickname(nick), phoneNumber(number),
	darkestSecret(darkSecret)
{
}

Contact::~Contact()
{
}
static std::string pasrString(const std::string &str)
{
	if (str.size() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::printContact(int index)
{
	std::string Fname = pasrString(firstName);
	std::string Lname = pasrString(lastName);
	std::string nick = pasrString(nickname);

	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << Fname << "|";
	std::cout << std::setw(10) << Lname << "|";
	std::cout << std::setw(10) << nick << "|";
	std::cout << std::endl;
}

void Contact::getFullContact() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
}
