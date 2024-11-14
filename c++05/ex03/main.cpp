#include "classHeader.hpp"

int main()
{
	Intern	jan;
	Pointer	prezp(jan.makeForm("presidential pardon", "Henk"));
	Pointer	shrubc(jan.makeForm("shrubbery creation", "Public library"));
	Pointer	robotr(jan.makeForm("robotomy request", "Dolores"));
	Bureaucrat god("God", 1);

	try
	{
		Pointer	Invalid(jan.makeForm("lka;j;ejsalkeflsaf", "Dolores"));
	}
	catch (std::exception& e)
	{
		std::cerr << "whoops" << std::endl;
	}
	god.signForm(prezp.obj());
	prezp.obj().execute(god);
	god.signForm(shrubc.obj());
	shrubc.obj().execute(god);
	god.signForm(robotr.obj());
	robotr.obj().execute(god);
}
