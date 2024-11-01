#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	public:
	
	AForm() = delete;
	~AForm() = default;
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& original) = delete;
	AForm&	operator=(const AForm& original) = delete;

	int					getSignGrade()	const;
	int 				getExecGrade()	const;
	bool 				getSignedStatus()	const;
	const std::string&	getName()	const;

	void				beSigned(const Bureaucrat& Bureaucrat);
	virtual void		executeForm(const Bureaucrat& Bureaucrat) = 0;
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

	class FormNotSignedException : public std::runtime_error
	{
		public:
		FormNotSignedException();
	};

	private:

	const std::string	_name;
	const int			signGrade;
	const int			execGrade;
	bool				_signed;
};
