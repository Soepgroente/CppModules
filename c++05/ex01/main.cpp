#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat	Sjon("Sjonnie", 55);
	Bureaucrat	Henk("Henkie", 125);
	Form		becomeDictator("Dictator", 100, 20);

	Sjon.signForm(becomeDictator);
	try
	{
		becomeDictator.beSigned(Henk);
	}
	catch (std::exception& e)
	{
		std::cout << "Whoopsie" << std::endl;
	}
}