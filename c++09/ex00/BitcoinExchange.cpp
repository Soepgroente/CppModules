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
		if (stream >> dummy)
			throw std::runtime_error("Invalid file format");
		if (date)
	}
}
/*
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>*/