#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Pointer.hpp"
#include "Intern.hpp"

int main()
{
	Intern	jan;
	// AForm*	ppForm;
	// AForm*	scForm;
	// AForm*	rrForm;
	// AForm*	invalidForm;
	Pointer	smartpp(jan.makeForm("presidential pardon", "Henk"));
	Pointer	smartsc(jan.makeForm("shrubbery creation", "Public library"));
	Pointer	smartrr(jan.makeForm("robotomy request", "Dolores"));
	// Pointer	smartInvalid(jan.makeForm("lka;j;ejsalkeflsaf", "Dolores"));
	Bureaucrat god("God", 1);

	god.signForm(*smartpp.form);
	smartpp.form->executeForm(god);
	god.signForm(*smartsc.form);
	smartsc.form->executeForm(god);
	god.signForm(*smartrr.form);
	smartrr.form->executeForm(god);
}