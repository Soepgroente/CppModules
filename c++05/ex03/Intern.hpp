#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	public:
	
	Intern() = default;
	~Intern() = default;
	Intern(const Intern& original) = delete;
	Intern&	operator=(const Intern& original) = delete;

	AForm*	makeForm(const std::string& formName, const std::string& formTarget);
};
