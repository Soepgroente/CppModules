#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
	{
		throw GradeTooHighException(); 
	}
	if (_grade > 150)
	{
		throw GradeTooLowException();
	}
}

const std::string&	Bureaucrat::getName()	const
{
	return (_name);
}

int	Bureaucrat::getGrade()	const
{
	return (this->_grade);
}

void	Bureaucrat::upGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() << " because form is already signed or insufficient permissions" << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (out);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("Grade too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("Grade too low")
{
}