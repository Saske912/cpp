//##################################################################
//                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣴⣖⣁⣀⣀⡄⠀⠀⠀
//                                       ⠀⠀⠀⠀⠀⠀⢀⣀⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣤⣄⣀⣀
//                                       ⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁
//                                      ⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀
//                                      ⠀⠀⠀⠀⠀⣼⣿⡟⠀⢠⡲⠖⠀⣿⣿⣿⣿⣿⣿⣿⣉⠁⠀⠀⠀
//  ╱╱╱╱╭━╮╭╮                               ⣼⣿⣿⡷⢤⠤⠤⣥⡤⣿⠿⣿⣿⣿⡿⣿⣿⣷⡀
//  ╱╱╱╱┃╭╯┃┃                           ⠀⣀⣠⣼⣿⣿⣿⣧⠑⠟⠀⠈⠙⠱⢦⣿⣿⣿⠁⣸⣿⣿⣇⠀
//  ╭━━┳╯╰┳┫┃╭━━╮                       ⠊⠉⠉⠉⠉⠩⠞⠁⠀⠀⠄⠀⠀⡴⣿⣿⣿⠗⣵⣿⠡⠉⠉⠁⠀
//  ┃╭╮┣╮╭╋┫┃┃┃━┫                              ⠀⢡⠀⠀⠀⢈⣾⣟⣵⣯⣼⣿⣬⣄⣀⠀⠀
//  ┃╰╯┃┃┃┃┃╰┫┃━┫                           ⠀⠀⣶⣶⣶⣾⣥⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀
//  ┃╭━╯╰╯╰┻━┻━━╯                           ⠀⢺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡄
//  ┃┃                                     ⢠⢤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⡄
//  ╰╯                                  ⠀⠠⣰⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠇⠀

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include "classArgs.hpp"
#ifndef MAX_STRINGS
# define MAX_STRINGS 1000
#endif

typedef std::string	s;

int		swapSubSequences(s *str, Args ar)
{
	int			i;
	std::string	tmp;
	int			len1;

	i = 0;
	tmp = *str;
	len1 = ar.SForcompare().length();
	while(tmp[i])
	{
		if (!tmp.compare(i, len1, ar.SForcompare()))
		{
			tmp.erase(i, len1);
			tmp.insert(i, ar.SForReplace());
		}
		i++;
	}
	*str = tmp;
	return (0);
}

void	insertStringsToFile(char *file, s *str, int i)
{
	int		k;

	std::ofstream	ofs(file);
	k = 0;
	while (k < i - 1)
	{
		ofs << str[k] << std::endl;
		k++;
	}
}

int		main(int ac, char **av)
{
	s		*str;
	int		i;

	if (ac == 4)
	{
		Args	ar(av[2], av[3]);

		if (!(str = new s[MAX_STRINGS]))
		{
			perror("new:str");
			return (-1);
		}
		std::ifstream	ifs(av[1]);
		i = 0;
		while(ifs.good())
		{
			std::getline(ifs, str[i]);
			if (swapSubSequences(&str[i], ar) == -1)
			{
				perror("swapSubSequences");
				return (-1);
			}
			i++;
		}
		ifs.close();
		insertStringsToFile(av[1], str, i);
		delete [] str;
	}
	return (0);
}