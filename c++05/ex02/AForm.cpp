#include "AForm.hpp"

AForm::AForm(const std::string& name, int sign, int exec) : _name(name), signGrade(sign), execGrade(exec), _signed(false)
{
	if (signGrade < 1 || execGrade < 1)
	{
		throw GradeTooHighException(); 
	}
	if (signGrade > 150 || execGrade > 150)
	{
		throw GradeTooLowException();
	}
}

const std::string&	AForm::getName()	const
{
	return (_name);
}

int	AForm::getSignGrade()	const
{
	return (signGrade);
}

int	AForm::getExecGrade()	const
{
	return (execGrade);
}

bool	AForm::getSignedStatus()	const
{
	return (_signed);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
	{
		_signed = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream&	AForm::operator<<(std::ostream& out)
{
	std::string	signedstatus = "signed";

	if (_signed == false)
		signedstatus = "un" + signedstatus;
	out << "AForm name: " << this->getName() << "\nAForm sign grade:" << this->getSignGrade();
	out << "\nAForm execution grade:" << this->getExecGrade() << "\nSign status: " << signedstatus << std::endl;
	return (out);
}

AForm::GradeTooHighException::GradeTooHighException() : std::runtime_error("Grade too high\n")
{
}

AForm::GradeTooLowException::GradeTooLowException() : std::runtime_error("Grade too low\n")
{
}

AForm::FormNotSignedException::FormNotSignedException() : std::runtime_error("Form isn't signed\n")
{
}