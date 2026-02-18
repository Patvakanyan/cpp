#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
  private:
	Contact con[8];

  public:
	PhoneBook();
	bool addContact(int &currentIndex, int &countContact);
	void searchContact(int countContact);
	~PhoneBook();
};

#endif
