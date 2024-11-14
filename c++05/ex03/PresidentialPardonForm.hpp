#pragma once

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public:
	
	PresidentialPardonForm() = delete;
	~PresidentialPardonForm() = default;
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& original) = delete;
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& original) = delete;

	void	executeForm()	const override;

	private:

	static const int	sign = 25;
	static const int	exec = 5;
	const std::string	_target;
};
