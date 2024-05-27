#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define FOREVER 1

void	replace_lines(std::ofstream& dest, std::ifstream& src, std::string s1, std::string s2)
{
	std::string	line;

	while (FOREVER)
	{
		std::getline(src, line, '\n');
		if (line.compare(s1) == 0)
			line = s2;
		dest << line;
		if (src.eof() == true)
			break ;
		dest << std::endl;
	}
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Please include a filename and strings s1 & s2" << std::endl;
		return (1);
	}
	std::ofstream	dest;
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		file;
	std::ifstream	src;

	file = argv[1];
	src.open(file);
	if (src.is_open() == false)
		return (2);
	dest.open("dest.txt");
	if (dest.is_open() == false)
	{
		src.close();
		return (3);
	}
	replace_lines(dest, src, s1, s2);
	src.close();
	dest.close();
}
