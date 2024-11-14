#include "classHeader.hpp"

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

void	AForm::execute(const Bureaucrat& executor)	const
{
	if (this->getSignedStatus() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > signGrade)
		throw GradeTooLowException();
	this->executeForm();
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getSignedStatus() == true)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream&		operator<<(std::ostream& out, const AForm& form)
{
	std::string	signedstatus = "signed";

	if (form.getSignedStatus() == false)
		signedstatus = "un" + signedstatus;
	out << "Form name: " << form.getName() << "\nForm sign grade: " << form.getSignGrade();
	out << "\nForm execution grade:" << form.getExecGrade() << "\nSign status: " << signedstatus << std::endl;
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