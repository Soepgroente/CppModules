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

Bureaucrat::~Bureaucrat()
{
}

void	Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
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

void	Bureaucrat::signForm(const Form& Form)	const
{
	if (Form.getSignedStatus() == true)
		std::cout << this->_name << " signed " << Form.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << Form.getName() << " because of insufficient permissions" << std::endl;
}

std::ostream&	Bureaucrat::operator<<(std::ostream& out)	const
{
	out << "Name: " << this->getName() << "\nGrade " << this->getGrade() << std::endl;
	return (out);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("Grade too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("Grade too low")
{
}