#include "ScalarConverter.hpp"

enum	types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

static void	printOutput(const std::string (&output)[4])
{
	std::cout << output[CHAR] << std::endl;
	std::cout << output[INT] << std::endl;
	std::cout << output[FLOAT] << std::endl;
	std::cout << output[DOUBLE] << std::endl;
}

void	ScalarConverter::convert(const std::string& input)
{
	const std::string	infs[8] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff", "inf", "inff"};

	std::string	output[4] = {"char: ", "int :", "float: ", "double: "};

	for (int i = 0; i < 8; i++)
	{
		if (input == infs[i])
		{
			output[CHAR] += "impossible";
			if (i < 2)
			{
				output[INT] += "impossible";
			}
		}
	}

}