#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
	public:
	
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& original) = delete;
	ScalarConverter& operator=(const ScalarConverter& original) = delete;
	~ScalarConverter() = delete;
	
	static void	convert(const std::string& input);
};
