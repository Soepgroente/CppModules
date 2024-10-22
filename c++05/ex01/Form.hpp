#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

class Form
{
	public:
	
	Form() = delete;
	~Form();
	Form(const std::string& name, int signGrade, int execGrade);
	Form(const Form& original);
	Form&	operator=(const Form& original);

	int					getSignGrade()	const;
	int 				getExecGrade()	const;
	bool 				getSignedStatus()	const;
	const std::string&	getName()	const;

	void				beSigned(const Bureaucrat& Bureaucrat);
	std::ostream&		operator<<(std::ostream& out);

	class GradeTooHighException : public std::runtime_error
	{
		public:
		GradeTooHighException(); 
	};

	class GradeTooLowException : public std::runtime_error
	{
		public:
		GradeTooLowException();
	};

	private:

	const std::string	_name;
	bool				_signed;
	const int			signGrade;
	const int			execGrade;
};
