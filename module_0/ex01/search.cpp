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
//  ╰╯                                  ⠀⠠⣰⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠇⠀⠀⠀⠀⠀
//#################################################################

#include "Crappy.hpp"

void    out_info( t_args *s, int k )
{
    std::cout << "first name: " << s[k].fname << std::endl;
    std::cout << "last name: " << s[k].lname << std::endl;
    std::cout << "nickname: " << s[k].nickname << std::endl;
    std::cout << "login: " << s[k].login << std::endl;
    std::cout << "postal address: " << s[k].paddr << std::endl;
    std::cout << "email address: " << s[k].eaddr << std::endl;
    std::cout << "phone number: " << s[k].pnum << std::endl;
    std::cout << "birthday date: " << s[k].bdate << std::endl;
    std::cout << "favorite meal: " << s[k].fmeal << std::endl;
    std::cout << "underwear color: " << s[k].uwcolor << std::endl;
    std::cout << "darkest secret: " << s[k].dsecret << std::endl;
}

void    print_directly( t_args *s, std::string tmp, int i )
{
    int         k;

    while (1)
    {
        k = 0;
        if (!s[0].index)
        {
            std::cout << "list empty" << std::endl;
            break ;
        }
        std::cin >> tmp;
        while (k <= i)
        {
            if (tmp.size() == 1 && tmp[0] == s[k].index)
            {
                out_info(s, k);
                break ; 
            }
            k++;
        }
        if (k > i)
        {
            if (s[0].index)
                std::cout << "enter from " << s[0].index << " to " \
                << s[i - 1].index << std::endl;
        }
        else
            break ;
    }
}

void    get_list_contacts( Crappy *s)
{
    int         i;
    std::string tmp;
    t_args      data[8];

    i = 0;
    data[i] = s[i].get_string();
    while (data[i].index)
    {
        std::cout << '|' << std::setw(10) << data[i].index << '|';
        if (data[i].fname.size() <= 10)
            std::cout << std::setw(10) << data[i].fname << '|';
        else
            std::cout << data[i].fname.substr(0, 9) << ".|";
        if (data[i].lname.size() < 11)
            std::cout << std::setw(10) << data[i].lname << '|';
        else
            std::cout << data[i].lname.substr(0, 9) << ".|";
        if (data[i].nickname.size() < 11)
            std::cout << std::setw(10) << data[i].nickname  << '|' << std::endl;
        else
            std::cout << data[i].nickname.substr(0, 9) << ".|" << std::endl;
        i++;
        data[i] = s[i].get_string();
    }
    print_directly(data, tmp, i);
}
