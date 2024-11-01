#include "Form.hpp"

Form::Form(const std::string& name, int sign, int exec) : _name(name), signGrade(sign), execGrade(exec)
{
	_signed = false;
	if (signGrade < 1 || execGrade < 1)
	{
		throw GradeTooHighException(); 
	}
	if (signGrade > 150 || execGrade > 150)
	{
		throw GradeTooLowException();
	}
}

Form::~Form()
{
}

Form::Form(const Form& original) : _name(original._name), \
	signGrade(original.signGrade), execGrade(original.execGrade), _signed(original._signed)
{
}

const std::string&	Form::getName()	const
{
	return (_name);
}

int	Form::getSignGrade()	const
{
	return (signGrade);
}

int	Form::getExecGrade()	const
{
	return (execGrade);
}

bool	Form::getSignedStatus()	const
{
	return (_signed);
}

void	Form::beSigned(const Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() <= signGrade)
	{
		_signed = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream&	Form::operator<<(std::ostream& out)
{
	std::string	signedstatus = "signed";

	if (_signed == false)
		signedstatus = "un" + signedstatus;
	out << "Form name: " << this->getName() << "\nForm sign grade:" << this->getSignGrade();
	out << "\nForm execution grade:" << this->getExecGrade() << "\nSign status: " << signedstatus << std::endl;
	return (out);
}

Form::GradeTooHighException::GradeTooHighException() : std::runtime_error("Grade too high")
{
}

Form::GradeTooLowException::GradeTooLowException() : std::runtime_error("Grade too low")
{
}