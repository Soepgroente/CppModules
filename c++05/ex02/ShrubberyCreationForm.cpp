#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", sign, exec), _target(target)
{
}

void	ShrubberyCreationForm::sheerShrubbery(const std::string& filename)
{
	std::ofstream	file;
	const std::string tree = ".              .              ;%     ;;   \n                  ,           ,                :;%  %;   \n                    :         ;                   :;%;'     .,   \n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'   \n                        `@%.  `;@%.      ;@@%;         \n                          `@%%. `@%%    ;@@%;        \n                            ;@%. :@%%  %@@%;       \n                              %@bd%%%bd%%:;     \n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '         \n                                %@@@o%;:(.,'         \n                            `.. %@@@o%::;         \n                               `)@@@o%::;         \n                                %@@(o)::;        \n                               .%@@@@%::;         \n                               ;%@@@@%::;.          \n                              ;%@@@@%%:;;;. \n                          ...;%@@@@@%%:;;;;,..    ";

	file.open(filename + "_shrubbery", std::ofstream::out);
	if (file.is_open() == false)
		throw std::runtime_error("Could not open file");
	file << tree;
	file.close();
}

void	ShrubberyCreationForm::executeForm(const Bureaucrat& bureaucrat)
{
	if (this->getSignedStatus() == false)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() <= this->getExecGrade())
	{
		ShrubberyCreationForm::sheerShrubbery(this->getName());
	}
	else
		throw GradeTooLowException();
}