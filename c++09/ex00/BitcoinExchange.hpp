#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <regex>
#include <sstream>
#include <string>

#define FOREVER 1

class BitcoinExchange
{
	public:

	BitcoinExchange() = delete;
	BitcoinExchange(const std::string& filePath);
	BitcoinExchange(const BitcoinExchange& other) = delete;
	BitcoinExchange&	operator=(const BitcoinExchange& other) = delete;
	~BitcoinExchange() = default;
	
	private:

	std::map<std::string, std::string>		database;

	void	parseCsv();
	float	getTotalAmount(const std::string& date, const std::string& amount);
	bool	isDateValid(const std::string& date);
};
