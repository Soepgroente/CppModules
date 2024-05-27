#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	str_PTR = &str;
	std::string&	str_REF = str;
	
	std::cout << "Address of str variable:     " << &str << std::endl;
	std::cout << "Address of str_PTR variable: " << &str_PTR << std::endl;
	std::cout << "Address of str_REF variable: " << &str_REF << std::endl << std::endl;

	std::cout << "Value of str               : " << str << std::endl;
	std::cout << "Value pointed to by str_PTR: " << *str_PTR << std::endl;
	std::cout << "Value of str_REF:            " << str_REF << std::endl;
}