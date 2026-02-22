#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
  public:
	Contact();
	Contact(std::string LName, std::string FName, std::string nick,
		std::string darkSecret, std::string number);
	void getFullContact() const;
	void printContact(int index);
	~Contact();
};

#endif
