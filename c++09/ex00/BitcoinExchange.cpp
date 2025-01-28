#include "BitcoinExchange.hpp"

static bool	checkDay(int year, int day, int month)
{
	if (day < 0 || day > 31)
		return (false);
	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			return (day <= 29);
		return (day <= 28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	return (true);
}

static bool	checkMonth(int month)
{
	return (month >= 0 && month <= 12);
}

static bool	checkYear(int year)
{
	return (year <= 2025);
}

static bool	isPriceValid(float price)
{
	return (price >= 0.0f && price <= 1000.0f);
}

static bool	isDateValid(const std::string& date)
{
	std::regex	datePattern(R"((\d{4})-(\d{2})-(\d{2}))");
	std::smatch	matches;

	if (std::regex_match(date, matches, datePattern))
	{
		int year = std::stoi(matches[1].str());
		int month = std::stoi(matches[2].str());
		int day = std::stoi(matches[3].str());

		if (checkYear(year) && checkMonth(month) && checkDay(year, day, month))
			return (true);
	}
	return (false);
}

BitcoinExchange::BitcoinExchange(const std::string& filePath)
{
	std::ifstream	file(filePath);
	std::string 	line;
	std::string 	date;
	std::string		price;
	std::string		dummy;

	if (file.is_open() == false)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return ;
	}

	while (std::getline(file, line))
	{
		std::istringstream stream(line);
		
		stream >> date >> dummy >> price;
		if (dummy != "|" || stream >> dummy)
		{
			std::cerr << "Error: bad input" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		input.insert(std::make_pair(date, price));
	}
}

void	BitcoinExchange::parseDatabase()
{
	std::fstream file("data.csv");
	std::string line;

	if (file.is_open() == false)
	{
		std::cerr << "Error: could not open file." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::getline(file, line); // skip the first line
	while (std::getline(file, line))
	{
		database.insert(std::make_pair(line.substr(0, line.find_first_of(',') + 1), std::stof(line.substr(line.find_first_of(',') + 1))));
	}
	file.close();
}

static bool	checkInputLine(const std::pair<std::string, std::string>& input)
{
	if (isDateValid(input.first) == false || input.second.size() == 0)
	{
		std::cout << "Error: bad input" << input.first << " " << input.second << std::endl;
		return (false);
	}
	try
	{
		if (isPriceValid(std::stof(input.second)) == false)
			throw std::out_of_range("incorrect value");
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "Error: number incorrectly formatted: " << input.second << std::endl;
		return (false);
	}
	catch (std::out_of_range& e)
	{
		if (input.second[0] == '-')
			std::cout << "Error: not a positive number" << input.second << std::endl;
		else
			std::cout << "Error: number too large" << input.second << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::run()
{
	parseDatabase();

	for (const std::pair<std::string, std::string>& it : input)
	{
		if (checkInputLine(it) == false)
			continue ;
		
	}
}
