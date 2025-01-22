#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>

class BitcoinExchange
{
	public:

	BitcoinExchange() = default;
	BitcoinExchange(const std::string& filePath);
	~BitcoinExchange() = default;

	void	print(std::string& date) const;

	private:

	std::map<std::string, float>	data;
};