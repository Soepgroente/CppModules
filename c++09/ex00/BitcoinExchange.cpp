#include "BitcoinExchange.hpp"

static bool	checkDay(int year, int day, int month)
{
	if (day <= 0 || day > 31)
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
	return (month >= 1 && month <= 12);
}

static bool	checkYear(int year)
{
	return (year <= 2025);
}

bool	BitcoinExchange::isDateValid(const std::string& date)
{
	std::string	firstDate = database.begin()->first;
	std::string	lastDate = database.rbegin()->first;

	if (firstDate.substr(0, 4) > date.substr(0, 4) || lastDate.substr(0, 4) < date.substr(0, 4))
		return (false);
	try
	{
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));
		
		if (date.size() != 10 || date[4] != '-' || date[7] != '-')
			return (false);
		return (checkYear(year) == true && checkMonth(month) == true && checkDay(year, day, month) == true);
	}
	catch (std::exception& e)
	{
		return (false);
	}
}

/*	Parses database. Then input file line by line, printing result or error messages when there's something wrong.
	Skips first line which holds no data	*/

BitcoinExchange::BitcoinExchange(const std::string& filePath)
{
	std::ifstream	file("./" + filePath);
	std::string 	line;

	parseCsv();

	if (file.is_open() == false)
	{
		std::cerr << "Error: Could not open file: " << filePath << std::endl;
		return ;
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream	stream(line);
		std::string 		date;
		std::string			price;
		std::string			dummy;
		std::string			dummy2;
		float				priceFloat;
		
		stream >> date >> dummy >> price >> dummy2;

		try
		{
			if (dummy != "|" || dummy2.empty() == false)
			{
				throw std::runtime_error("bad input");
			}
			priceFloat = std::stof(price);
		}
		catch (std::exception& e)
		{
			date = "Error: bad input => ";
			priceFloat = 1.0f;
		}
		if (priceFloat < 0)
		{
			std::cout << "Error: not a positive number" << std::endl;
		}
		else if (priceFloat > 1000)
		{
			std::cout << "Error: too large a number" << std::endl;
		}
		else if (date[0] == 'E')
		{
			std::cout << date << line << std::endl;
		}
		else if (isDateValid(date) == false)
		{
			std::cout << "Error: bad input => " << date << " " << dummy << " " << price << std::endl;
		}
		else
		{
			std::cout << date << " => " << price << " = " << getTotalAmount(date, price) << std::endl;
		}
	}
}

/*	No error checking on the data as the database is provided by the subject and static.
	Skips first line which holds no data	*/

void	BitcoinExchange::parseCsv()
{
	std::fstream	file("data.csv");
	std::string		line;

	if (file.is_open() == false)
	{
		std::cerr << "Error: could not open data.csv" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		database.insert(std::make_pair(line.substr(0, line.find_first_of(',')), line.substr(line.find_first_of(',') + 1)));
	}
	file.close();
}

/*	Loops through database until the key (date) is later than the requested date to get prices at rounded down dates.	*/

float	BitcoinExchange::getTotalAmount(const std::string& date, const std::string& amount)
{
	float amt = std::stof(amount);
	float price;
	int day[2], month[2], year[2];

	year[0] = std::stoi(date.substr(0, 4));
	month[0] = std::stoi(date.substr(5, 2));
	day[0] = std::stoi(date.substr(8, 2));

	for (const auto& data : database)
	{
		year[1] = std::stoi(data.first.substr(0, 4));
		month[1] = std::stoi(data.first.substr(5, 2));
		day[1] = std::stoi(data.first.substr(8, 2));
		if (year[0] < year[1])
		{
			break ;
		}
		else if (year[0] == year[1] && month[0] < month[1])
		{
			break ;
		}
		else if (year[0] == year[1] && month[0] == month[1] && day[0] < day[1])
		{
			break ;
		}
		price = std::stof(data.second);
	}
	return (amt * price);
}
