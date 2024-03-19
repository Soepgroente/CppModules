#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}

static bool	parse_attempt(int& index, std::string& search)
{
	try
	{
        index = std::stoi(search);
    }
	catch (std::invalid_argument)
	{
		std::cout << "\nPlease insert a valid index" << std::endl;
		return (false);
    }
	return (true);
}

void	Phonebook::add_contact()
{
	static int i = 0;
	
	entries[i].get_info(i + 1);
	i++;
	if (i == 8)
		i = 0;
}

void	Phonebook::search_contact()
{
	std::string search;
	int	index = 0;

	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "Name" << "|";
	std::cout << std::setw(10) << std::right << "Last name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		this->entries[i].show_index();
	}
	std::cout << "\nPlease choose which contact to display" << std::endl;
	std::cin.ignore(LLONG_MAX, '\n');
	while (index == 0)
	{
		getline(std::cin, search);
		parse_attempt(index, search);
	}
	this->entries[index - 1].show_contact();
}

