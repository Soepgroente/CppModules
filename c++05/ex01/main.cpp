#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	Sjon("Sjonnie", 55);
	Bureaucrat	Henk("Henkie", 125);
	Bureaucrat	god("God", 1);
	Form		becomeDictator("Become dictator", 100, 20);

	std::cout << becomeDictator << std::endl;
	try
	{
		becomeDictator.beSigned(Henk);
	}
	catch (std::exception& e)
	{
		std::cout << "Whoopsie daisy couldn't sign" << std::endl;
	}
	becomeDictator.beSigned(god);
	Sjon.signForm(becomeDictator);
}