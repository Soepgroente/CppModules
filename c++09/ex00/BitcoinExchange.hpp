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
	
	void	run();

	private:

	std::map<std::string, float>	database;
	std::map<std::string, std::string>	input;

	void	parseDatabase();
};

typedef std::map<std::string, float>::const_iterator MapIterator;