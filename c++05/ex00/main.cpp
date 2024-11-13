#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Sjon("Sjonnie", 55);
	Bureaucrat	Harry("Harry", 1);

	Harry.downGrade();
	std::cout << Harry;
	Harry.upGrade();
	try
	{
		Harry.upGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "whoopsie" << std::endl;
	}
	// Harry.upGrade();
}