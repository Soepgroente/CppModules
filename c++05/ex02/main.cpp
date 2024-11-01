#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

void	tryToDoThing(AForm& form, const Bureaucrat& person)
{
	try
	{
		form.executeForm(person);
	}
	catch (std::exception & e)
	{
		std::cerr << "Could not execute " << form.getName() << std::endl;
		return ;
	}
	std::cout << "Executed " << form.getName() << " successfully" << std::endl;
}

int main()
{
	Bureaucrat	sucker("Zlad", 150);
	Bureaucrat	sjon("Sjonnie", 55);
	Bureaucrat	approver("Henk", 10);
	Bureaucrat	universalGod("Vincent", 1);

	/*	Should be smart pointers for proper memory management but is not allowed yet	*/
	AForm*		shrubbery = new ShrubberyCreationForm("Outer space");
	AForm*		robotkill = new RobotomyRequestForm("Marvin");
	AForm*		criminal = new PresidentialPardonForm("Cpp05 evaluator");

	shrubbery->executeForm(sjon);
	robotkill->executeForm(sjon);
	criminal->executeForm(sjon);

	shrubbery->beSigned(approver);
	robotkill->beSigned(approver);
	criminal->beSigned(approver);

	tryToDoThing(*shrubbery, sucker);
	tryToDoThing(*robotkill, sucker);
	tryToDoThing(*criminal, sucker);

	tryToDoThing(*shrubbery, universalGod);
	tryToDoThing(*robotkill, universalGod);
	tryToDoThing(*criminal, universalGod);
}