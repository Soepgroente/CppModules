#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:

	void	complain(std::string level);
	Harl();
	~Harl();

	private:

	void 			debug(void);
	void 			info(void);
	void 			warning(void);
	void 			error(void);
	std::string		levels[4];
	void			(Harl::*func[4])(void);
};

#endif