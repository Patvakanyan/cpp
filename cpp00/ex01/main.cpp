#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	int			currentIndex;
	int			countContact;

	currentIndex = 0;
	countContact = 0;
	std::string command;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nError reading input.\nExiting." << std::endl;
			break ;
		}
		if (command.empty())
			continue ;
		if (command == "ADD")
		{
			if (!phoneBook.addContact(currentIndex, countContact))
			{
				std::cout << "\nError adding contact." << std::endl;
				std::cout << "Exiting." << std::endl;
				break;
			}
			else
				std::cout << "Contact added successfully." << std::endl;
		}
		else if (command == "SEARCH")
			phoneBook.searchContact(countContact);
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
