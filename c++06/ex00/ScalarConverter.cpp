#include "ScalarConverter.hpp"

enum	types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

static void	checkInfinities(const std::string& input, std::string (&output)[4])
{
	const std::string	infs[8] = {"nan", "nanf", "-inf", "+inf", "-inff", "+inff", "inf", "inff"};

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

static void	charLiteral(const std::string& input, std::string (&output)[4])
{

}

static void	printOutput(const std::string (&output)[4])
{
	std::cout << output[CHAR] << std::endl;
	std::cout << output[INT] << std::endl;
	std::cout << output[FLOAT] << std::endl;
	std::cout << output[DOUBLE] << std::endl;
}

void	ScalarConverter::convert(const std::string& input)
{
	std::string	output[4] = {"char: ", "int :", "float: ", "double: "};

	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
		charLiteral(input, output);
	// checkInfinities()

}