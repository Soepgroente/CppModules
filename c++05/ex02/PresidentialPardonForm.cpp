#include "classHeader.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
	AForm("PresidentialPardonForm", sign, exec), _target(target)
{
}

void	PresidentialPardonForm::executeForm()	const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
