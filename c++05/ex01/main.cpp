#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat	Sjon("Sjonnie", 55);
	Form		becomeDictator("Dictator", 100, 20);

	Sjon.signForm(becomeDictator);
}