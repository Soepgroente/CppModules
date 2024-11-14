#pragma once

#include "AForm.hpp"
#include <stdexcept>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	public:
	
	Bureaucrat() = delete;
	~Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& original) = delete;
	Bureaucrat&	operator=(const Bureaucrat& original) = delete;

	const std::string&	getName()	const;
	int					getGrade()	const;
	void				downGrade();
	void				upGrade();

	void				signForm(AForm& Form);
	void				executeForm(const AForm& Form);

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
	int					_grade;
};

std::ostream&		operator<<(std::ostream& out, const Bureaucrat& bureaucrat);