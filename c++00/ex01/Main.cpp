#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

int32_t	main(void)
{
	class Phonebook	yellow_pages;
	std::string		user_input;

	std::cout << "Hello! Welcome to my phantastic phonebook!" << std::endl;
	while (true)
	{
		std::cout << "\nPlease choose ADD, SEARCH or EXIT" << std::endl;
		std::cin >> user_input;
		if (user_input == "ADD")
			yellow_pages.add_contact();
		else if (user_input == "SEARCH")
			yellow_pages.search_contact();
		else if (user_input == "EXIT")
			return (EXIT_SUCCESS);
	}
}