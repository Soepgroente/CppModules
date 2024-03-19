#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class Phonebook
{
	public:
		class Contact	entries[8];
	
	void	search_contact();
	void	add_contact();
	Phonebook();
	~Phonebook();
};

#endif