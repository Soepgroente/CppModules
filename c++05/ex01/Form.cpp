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
	if (Bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	else if (_signed == true)
	{
		throw FormAlreadySignedException();
	}
	else
		_signed = true;
}

std::ostream&		operator<<(std::ostream& out, const Form& form)
{
	std::string	signedstatus = "signed";

	if (form.getSignedStatus() == false)
		signedstatus = "un" + signedstatus;
	out << "Form name: " << form.getName() << "\nForm sign grade: " << form.getSignGrade();
	out << "\nForm execution grade:" << form.getExecGrade() << "\nSign status: " << signedstatus << std::endl;
	return (out);
}

Form::GradeTooHighException::GradeTooHighException() : std::runtime_error("Grade too high")
{
}

Form::GradeTooLowException::GradeTooLowException() : std::runtime_error("Grade too low")
{
}

Form::FormAlreadySignedException::FormAlreadySignedException() : std::runtime_error("Form already signed")
{
}