#pragma once

#include "Form.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

class Bureaucrat
{
	public:
	
	Bureaucrat() = delete;
	~Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& original) = delete;
	Bureaucrat&	operator=(const Bureaucrat& original) = delete;

	void				setGrade(int grade);
	const std::string&	getName()	const;
	int					getGrade()	const;
	void				downGrade();
	void				upGrade();

	void				signForm(const Form& Form)	const;
	std::ostream&		operator<<(std::ostream& out)	const;

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
