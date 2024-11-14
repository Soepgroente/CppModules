#pragma once

#include "Form.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

class Form;

class Bureaucrat
{
	public:
	
	Bureaucrat() = delete;
	~Bureaucrat() = default;
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& original) = delete;
	Bureaucrat&	operator=(const Bureaucrat& original) = delete;

	const std::string&	getName()	const;
	int					getGrade()	const;
	void				downGrade();
	void				upGrade();

	void				signForm(Form& form);

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