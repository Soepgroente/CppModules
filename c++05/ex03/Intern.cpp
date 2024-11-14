#include "Intern.hpp"

static AForm*	createPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

static AForm*	createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	const std::string names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	AForm*	(*f[3])(const std::string&) = {&createPardon, &createRobotomy, &createShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (f[i](formTarget));
		}
	}
	throw FormCreationError();
}

Intern::FormCreationError::FormCreationError() : std::runtime_error("Form not found")
{
}