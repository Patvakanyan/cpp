#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact con[8];
	public:
	PhoneBook();
	void addContact();
	~PhoneBook();
};

#endif
