#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	jan;
	AForm*	ppForm;
	AForm*	scForm;
	AForm*	rrForm;
	AForm*	invalidForm;
	Bureaucrat god("God", 1);

	ppForm = jan.makeForm("presidential pardon", "Henk");
	scForm = jan.makeForm("shrubbery creation", "Public library");
	rrForm = jan.makeForm("robotomy request", "Dolores");
	invalidForm = jan.makeForm("lka;j;ejsalkeflsaf", "Dolores");
	if (ppForm != nullptr)
	{
		god.signForm(*ppForm);
		ppForm->executeForm(god);
	}
	if (scForm != nullptr)
	{
		god.signForm(*scForm);
		scForm->executeForm(god);
	}
	if (rrForm != nullptr)
	{
		god.signForm(*rrForm);
		rrForm->executeForm(god);
	}
	if (invalidForm != nullptr)
	{
		god.signForm(*invalidForm);
		invalidForm->executeForm(god);
	}
}