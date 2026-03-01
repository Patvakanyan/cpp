#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}


bool	addNumberHelper(std::string &input, const std::string &prompt)
{
	while (true)
	{
		size_t i;
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return (false);
		if (input.empty())
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			continue ;
		}
		for (i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				std::cout << "Invalid input. Please try again." << std::endl;
				break ;
			}
		}
		if (i == input.length())
			break ;
	}
	return (true);
}

bool	addContactHelper(std::string &input, const std::string &prompt)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return (false);
		if (!input.empty())
			break ;
		std::cout << "Invalid input. Please try again." << std::endl;
	}
	return (true);
}

bool PhoneBook::addContact(int &currentIndex, int &countContact)
{
	std::string nick;
	std::string Fname;
	std::string Lname;
	std::string darkSecret;
	std::string number;
	if (!addContactHelper(Lname, "Enter Last Name: "))
		return (false);
	if (!addContactHelper(Fname, "Enter First Name: "))
		return (false);
	if (!addContactHelper(nick, "Enter Nickname: "))
		return (false);
	if (!addContactHelper(darkSecret, "Enter darkest secret: "))
		return (false);
	if (!addNumberHelper(number, "Enter Phone Number: "))
		return (false);
	PhoneBook::con[currentIndex] = Contact(Lname, Fname, nick, darkSecret,
			number);
	currentIndex = (currentIndex + 1) % 8;
	if (countContact < 8)
		countContact++;
	return (true);
}

void PhoneBook::searchContact(int countConutact)
{
	int	index;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "         Welcome to the PhoneBook App         " << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < countConutact; i++)
		con[i].printContact(i);
	std::cout << "---------------------------------------------" << std::endl;
	std::string input;
	while (true)
	{
		size_t i;
		std::cout << "Enter the index of the contact to view details: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "Error reading input. Please try again." << std::endl;
			return ;
		}
		if (input.empty())
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			continue ;
		}
		for (i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				std::cout << "Invalid input. Please try again." << std::endl;
				break ;
			}
		}
		if (i == input.length())
			break ;
	}
	index = atoi(input.c_str());
	if (index < 0 || index >= countConutact)
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return ;
	}
	con[index].getFullContact();
}
