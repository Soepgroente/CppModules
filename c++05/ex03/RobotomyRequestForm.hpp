#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
	public:
	
	RobotomyRequestForm() = delete;
	~RobotomyRequestForm() = default;
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& original) = delete;
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& original) = delete;

	void	executeForm()	const override;

	private:

	static const int	sign = 72;
	static const int	exec = 45;
	const std::string	_target;
};
