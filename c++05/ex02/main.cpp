#include "classHeader.hpp"

static void tryToSign(AForm& form, const Bureaucrat& person)
{
	try
	{
		form.beSigned(person);
	}
	catch (std::exception & e)
	{
		std::cerr << "Could not sign " << form.getName() << std::endl;
	}
}

static void	tryToExecute(AForm& form, const Bureaucrat& person)
{
	try
	{
		form.execute(person);
	}
	catch (std::exception & e)
	{
		std::cerr << "Could not execute " << form.getName() << std::endl;
	}
}

int main()
{
	Bureaucrat	sucker("Zlad", 150);
	Bureaucrat	sjon("Sjonnie", 55);
	Bureaucrat	approver("Henk", 10);
	Bureaucrat	universalGod("Vincent", 1);

	Pointer		shrubbery(new ShrubberyCreationForm("Outer space"));
	Pointer		robotkill(new RobotomyRequestForm("Marvin"));
	Pointer		criminal(new PresidentialPardonForm("Cpp05 evaluator"));

	tryToSign(shrubbery.obj(), sjon);
	tryToSign(robotkill.obj(), sjon);
	tryToSign(criminal.obj(), sjon);

	approver.signForm(shrubbery.obj());
	approver.signForm(robotkill.obj());
	approver.signForm(criminal.obj());

	tryToExecute(shrubbery.obj(), sucker);
	tryToExecute(robotkill.obj(), sucker);
	tryToExecute(criminal.obj(), sucker);

	tryToExecute(shrubbery.obj(), universalGod);
	tryToExecute(robotkill.obj(), universalGod);
	tryToExecute(criminal.obj(), universalGod);
}
