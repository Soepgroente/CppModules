#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
	public:
	
	ShrubberyCreationForm() = delete;
	~ShrubberyCreationForm() = default;
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& original) = delete;
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& original) = delete;

	void	executeForm()	const override;

	private:

	static const int	sign = 145;
	static const int	exec = 137;
	const std::string	_target;
};
