#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

Contact::Contact()
{
	FirstName = "";
	LastName = "";
	NickName = "";
	PhoneNumber = "";
	DarkestSecret = "";
	index = 0;
}

Contact::~Contact()
{
}

std::string	Contact::truncate_field(std::string& input)
{
	const size_t	max_len = 10;

	if (input.length() > max_len)
		return (input.substr(0, max_len - 1) + ".");
	else
		return (input);
}

void Contact::show_contact()
{
	if (this->index == 0)
		return ;
	std::cout << std::left << std::endl;
	std::cout << std::setw(16) << "First name:" << this->FirstName << std::endl;
	std::cout << std::setw(16) << "Last name:" << this->LastName << std::endl;
	std::cout << std::setw(16) << "Nickname:" << this->NickName << std::endl;
	std::cout << std::setw(16) << "Phone number:" << this->PhoneNumber << std::endl;
	std::cout << std::setw(16) << "Darkest secret:" << this->DarkestSecret << std::endl;
}

void Contact::show_index()
{
	if (this->index == 0)
		return ;
	std::cout << std::setw(10) << std::right << this->index << "|";
	std::cout << std::setw(10) << std::right << truncate_field(this->FirstName) << "|";
	std::cout << std::setw(10) << std::right << truncate_field(this->LastName) << "|";
	std::cout << std::setw(10) << std::right << truncate_field(this->NickName) << "|" << std::endl;
}

std::string	Contact::prompt(std::string prompt)
{
	std::string	answer;

	std::cout << prompt << std::endl;
	getline(std::cin, answer);
	return (answer);
}

void	Contact::get_info(int in)
{
	std::cin.ignore(LLONG_MAX, '\n');
	FirstName = this->prompt("Please write your first name:");
	LastName = this->prompt("Please write your last name:");
	NickName = this->prompt("Please write a nickname:");
	PhoneNumber = this->prompt("Please insert your phone number:");
	DarkestSecret = this->prompt("Please share your darkest secret:");
	this->index = in;
}

