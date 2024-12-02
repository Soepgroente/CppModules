#include "ScalarConverter.hpp"

/*	Static cast converts the value of whatever you're casting to the new data type	*/

enum	types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

static bool	withinAscii(int c)
{
	return (c >= 0 && c <= 127);
}

static bool	isPrintable(int c)
{
	return (c >= 32 && c <= 126);
}

static void	handleCharacter(std::string &charString, int input)
{
	if (isPrintable(input) == true)
	{
		charString += "\'";
		charString += static_cast<char> (input);
		charString += "\'";
	}
	else if (withinAscii(input) == true)
		charString += "non displayable";
	else
		charString += "impossible";
}

static bool	inputIsInfinite(const std::string& input, std::string (&output)[4])
{
	const std::string	infs[6] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff"};

	for (int i = 0; i < 6; i++)
	{
		if (input == infs[i])
		{
			if (i < 2)
			{
				output[FLOAT] += std::to_string(std::numeric_limits<float>::quiet_NaN()) + "f";
				output[DOUBLE] += std::to_string(std::numeric_limits<double>::quiet_NaN());
			}
			else if (i < 4)
			{
				output[FLOAT] += std::to_string(-std::numeric_limits<float>::infinity()) + "f";
				output[DOUBLE] += std::to_string(-std::numeric_limits<double>::infinity());
			}
			else
			{
				output[FLOAT] += std::to_string(std::numeric_limits<float>::infinity()) + "f";
				output[DOUBLE] += std::to_string(std::numeric_limits<double>::infinity());
			}
			return (true);
		}
	}
	return (false);
}

static bool	inputIsChar(const std::string& input, std::string (&output)[4])
{
	if (input.size() != 1)
		return (false);
	if (std::isprint(input[0]) != 0 && std::isdigit(input[0]) == false)
	{
		output[CHAR] += "\'";
		output[CHAR] += input[0];
		output[CHAR] += "\'";
		output[INT] += std::to_string(static_cast<int>(input[0]));
		output[FLOAT] += std::to_string(static_cast<float> (input[0]));
		output[DOUBLE] += std::to_string(static_cast<double>(input[0]));
		return (true);
	}
	return (false);
}

static bool	inputIsInt(const std::string& input, std::string (&output)[4])
{
	if (input.find(".") != std::string::npos)
		return (false);
	int	conversion;
	try
	{
		conversion = std::stoi(input);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: invalid input" << std::endl;
		std::exit(EXIT_FAILURE);
    }
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: integer overflow, could not convert" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	handleCharacter(output[CHAR], conversion);
	output[INT] += std::to_string(conversion);
	output[FLOAT] += std::to_string(static_cast<float> (conversion));
	output[DOUBLE] += std::to_string(static_cast<double> (conversion));
	return (true);
}

static bool	inputIsFloat(const std::string& input, std::string (&output)[4])
{
	if (input.find("f") == std::string::npos)
		return (false);
	float	conversion;

	try
	{
		conversion = std::stof(input);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: invalid input" << std::endl;
		std::exit(EXIT_FAILURE);
    }
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: overFLOAT (haha). No but seriously, could not convert" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	handleCharacter(output[CHAR], static_cast<int> (conversion));
	if (static_cast<long> (conversion) > std::numeric_limits<int>::max() || \
		static_cast<long> (conversion) < std::numeric_limits<int>::min())
	{
		output[INT] += "integer overflow";
	}
	else	
	{
		output[INT] += std::to_string(static_cast<int> (conversion));
	}
	output[FLOAT] += std::to_string(conversion);
	output[DOUBLE] += std::to_string(static_cast<double> (conversion));
	return (true);
}

static bool	inputIsDouble(const std::string& input, std::string (&output)[4])
{
	double	conversion;

	try
	{
		conversion = std::stod(input);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: invalid input" << std::endl;
		std::exit(EXIT_FAILURE);
    }
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: overflow of double (seriously? That's impressive), could not convert" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (static_cast<long> (conversion) > std::numeric_limits<int>::max() || \
		static_cast<long> (conversion) < std::numeric_limits<int>::min())
	{
		output[INT] += "integer overflow";
		output[CHAR] += "impossible";
	}
	else	
	{
		handleCharacter(output[CHAR], static_cast<int> (conversion));
		output[INT] += std::to_string(static_cast<int> (conversion));
	}
	output[FLOAT] += std::to_string(static_cast<float> (conversion));
	output[DOUBLE] += std::to_string(conversion);
	return (true);
}

static void	trimFloats(std::string (&output)[4])
{
	while (output[FLOAT].back() == '0')
		output[FLOAT].pop_back();
	while (output[DOUBLE].back() == '0')
		output[DOUBLE].pop_back();
    if (output[FLOAT].back() == '.')
		output[FLOAT] += "0";
    if (output[DOUBLE].back() == '.')
		output[DOUBLE] += "0";
	output[FLOAT] += "f";
}

void	ScalarConverter::convert(const std::string& input)
{
	std::string	output[4] = {"char: ", "int: ", "float: ", "double: "};

	if (inputIsInfinite(input, output) == true)
	{
		output[CHAR] += "impossible";
		output[INT] += "impossible";
		printOutput(output);
	}
	else if (inputIsChar(input, output) == true ||
		inputIsInt(input, output) == true ||
		inputIsFloat(input, output) == true ||
		inputIsDouble(input, output) == true)
	{
		trimFloats(output);
		printOutput(output);
	}
}

void	ScalarConverter::printOutput(const std::string (&output)[4])
{
	std::cout << output[CHAR] << std::endl;
	std::cout << output[INT] << std::endl;
	std::cout << output[FLOAT] << std::endl;
	std::cout << output[DOUBLE] << std::endl;
}
