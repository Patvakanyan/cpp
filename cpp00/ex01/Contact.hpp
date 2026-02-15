#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Contact.hpp"

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	nickname;
		std::string	PhoneNumber;
	public:
	Contact();
	Contact(std::string LName, std::string FName, std::string nick, std::string number);
	~Contact();
};

#endif
