#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <random>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
	AForm("RobotomyRequestForm", sign, exec), _target(target)
{
}

void	RobotomyRequestForm::executeForm(const Bureaucrat& Bureaucrat)
{
	if (this->getSignedStatus() == true)
		this->robotomize(Bureaucrat);
	else
		throw FormNotSignedException();
}

void	RobotomyRequestForm::robotomize(const Bureaucrat& Bureaucrat)
{
	static std::mt19937 generator{std::random_device{}()};
	static std::uniform_int_distribution<int> boolMaker(false, true);

	if (Bureaucrat.getGrade() <= this->getExecGrade())
	{
		std::cout << "Brrrt bzzz wrrrr krrrrggghhh..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		std::cout << "..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if (boolMaker(generator) == true)
			std::cout << this->_target << " has been robotomized." << std::endl;
		else
			std::cout << "...failed to robotomize " << this->_target << std::endl;
	}
	else
		throw GradeTooLowException();
}