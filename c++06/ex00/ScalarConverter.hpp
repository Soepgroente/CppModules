#pragma once

#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <cfloat>

class ScalarConverter
{
	public:
	
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& original) = delete;
	ScalarConverter& operator=(const ScalarConverter& original) = delete;
	~ScalarConverter() = delete;
	
	static void	convert(const std::string& input);

	private:
	
	static void	printOutput(const std::string (&output)[4]);
	static void	printError();
};
