#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

#define ERROR_MSG "Please enter the filter level 'DEBUG', 'INFO', 'WARNING' or 'ERROR'"

class Harl
{
	public:
	int				filter;
	void	complain(std::string level);
	Harl();
	Harl(std::string input);
	~Harl();

	typedef enum s_filter
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR
	}	t_filter;

	private:
	void 			debug(void);
	void 			info(void);
	void 			warning(void);
	void 			error(void);
	std::string		levels[4];
	int				level_to_int(std::string input);
};


#endif