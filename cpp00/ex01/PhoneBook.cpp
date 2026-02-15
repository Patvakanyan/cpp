#include "PhoneBook.hpp"


void PhoneBook::addContact()
{
	std::string nick;
	std::string Fname;
	std::string Lname;

	std::cout << "Enter the first name: ";
	std::getline(std::cin, Fname);
	std::cout << "Enter the last name: ";
	std::getline(std::cin, Lname);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, nick);
}
