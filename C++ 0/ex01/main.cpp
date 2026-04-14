#include "header.hpp"


int main(void)
{
	PhoneBook book;

	std::cout << MAGENTA << "Welcome to your phonebook\n"<< WHITE;
	std::cout << BLUE << "Available commands:\n" << WHITE;
	std::cout << GREEN << "	ADD\n	SEARCH\n	EXIT\n\n" << WHITE;

	while (1)
	{
		std::string input;
		std::cout << BLUE << "Command: " << WHITE;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF detected exiting\n" << WHITE;
			std::exit(0);
		}
		for (size_t i = 0; i < input.length(); i++)
			input[i] = toupper(input[i]);
		if (strcmp(input.c_str(), "ADD") == 0)
			book.Add();
		else if (strcmp(input.c_str(), "SEARCH") == 0)
			book.Search();
		else if (strcmp(input.c_str(), "EXIT") == 0)
			break ;
		else
			std::cout << "Invalid request\n";
	}

}