#include <sstream>
#include <iostream>
#include <string>
#include <stack>

static float	plus(float a, float b)
{
	return (a + b);
}

static float	minus(float a, float b)
{
	return (a - b);
}

static float	multiply(float a, float b)
{
	return (a * b);
}

static float	divide(float a, float b)
{
	if (b == 0)
	{
		throw std::runtime_error("Error, division by zero");
	}
	return (a / b);
}

float	calculate(std::string input)
{
	std::stringstream	ss(input);
	std::string			tmp;
	std::stack<float>	nums;
	float a, b;

	while (ss.eof() == false)
	{
		ss >> tmp;
		if (tmp.size() > 1)
		{
			std::cerr << "Error, incorrect input string" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (std::isdigit(tmp[0]) != 0)
		{
			nums.push(tmp[0] - '0');
		}
		else if (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/')
		{
			if (nums.size() < 2)
			{
				std::cerr << "Error, incorrect input string (operator before two numbers)" << std::endl;
				std::exit(EXIT_FAILURE);
			}
			b = nums.top();
			nums.pop();
			a = nums.top();
			nums.pop();
			if (tmp[0] == '+')
			{
				nums.push(plus(a, b));
			}
			else if (tmp[0] == '-')
			{
				nums.push(minus(a, b));
			}
			else if (tmp[0] == '*')
			{
				nums.push(multiply(a, b));
			}
			else if (tmp[0] == '/')
			{
				nums.push(divide(a, b));
			}
		}
		else
		{
			std::cerr << "Error, incorrect character in input string" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	return (nums.top());
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error, incorrect number of arguments. Usage: ./RPN \"1 5 - 3 + 4 *\"" << std::endl;
		return (1);
	}
	std::cout << calculate(argv[1]) << std::endl;
	return (0);
}