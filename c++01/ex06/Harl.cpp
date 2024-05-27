#include "Harl.hpp"

Harl::Harl()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

Harl::Harl(std::string input)
{
	filter = -1;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	for (int i = 0; i < 4; i++)
	{
		if (input == levels[i])
		{
			filter = i;
			break ;
		}
	}
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having veggie bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe veggie bacon costs more money. ";
	std::cout << "You didn't put enough in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra salad for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

int	Harl::level_to_int(std::string input)
{
	for (int i = 0; i < 4; i++)
	{
		if (input == levels[i])
			return (i);
	}
	return (4);
}

void	Harl::complain(std::string level)
{
	int	num;

	num = level_to_int(level);
	if (filter > num)
		num = filter;
	switch (num)
	{
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARNING:
			this->warning();
		case ERROR:
			this->error();
			break ;
		default:
			std::cerr << "Harl does not understand, please try 'DEBUG', 'INFO', 'WARNING' or 'ERROR'" << std::endl;
	}
}