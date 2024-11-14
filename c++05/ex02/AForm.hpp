#pragma once

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
	
	AForm() = delete;
	virtual ~AForm() = default;
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& original) = delete;
	AForm&	operator=(const AForm& original) = delete;

	int					getSignGrade()	const;
	int 				getExecGrade()	const;
	bool 				getSignedStatus()	const;
	const std::string&	getName()	const;

	void				beSigned(const Bureaucrat& bureaucrat);
	void				execute(const Bureaucrat& executor)	const;
	virtual void		executeForm() const = 0;

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

std::ostream&		operator<<(std::ostream& out, const AForm& form);