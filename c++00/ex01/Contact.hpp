#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Phonebook.hpp"

class Contact
{
	private:
		std::string	FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	private:
	
	std::string	prompt(std::string prompt);
	std::string	truncate_field(std::string& input);
	
	public:
		int	index;

	public:

	void	show_index();
	void	show_contact(void);
	void	get_info(int in);
	Contact();
	~Contact();
};

#endif