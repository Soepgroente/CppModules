#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
	AForm("PresidentialPardonForm", sign, exec), _target(target)
{
}

void	PresidentialPardonForm::executeForm(const Bureaucrat& Bureaucrat)
{
	if (this->getSignedStatus() == true)
		this->pardon(Bureaucrat);
	else
		std::cout << "Could not execute, form is not signed" << std::endl;
}

void	PresidentialPardonForm::pardon(const Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->getExecGrade())
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw GradeTooLowException();
}