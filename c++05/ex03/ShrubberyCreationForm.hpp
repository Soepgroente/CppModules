#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
	
	ShrubberyCreationForm() = delete;
	~ShrubberyCreationForm() = default;
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& original) = delete;
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& original) = delete;

	void	executeForm(const Bureaucrat& bureaucrat)	override;

	private:

	void			sheerShrubbery();
	static const int	sign = 145;
	static const int	exec = 137;
	const std::string	_target;
};
