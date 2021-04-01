//
//                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣴⣖⣁⣀⣀⡄⠀⠀⠀
//                                       ⠀⠀⠀⠀⠀⠀⢀⣀⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣤⣄⣀⣀
//                                      ⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁
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
// 23.02.2021⠀⠀⠀⠀
//
#include "header.h"
#include "Fixed.hpp"
#include <string>
#include <sstream>

int     get_count_brackets(std::string str)
{
    int     open;
    int     close;
    int     tmp;

    open = 0;
    close = 0;
    tmp = 0;
    while ((tmp = str.find('(', tmp)) != std::string::npos)
    {
        open++;
        tmp++;
    }
    tmp = 0;
    while ((tmp = str.find(')', tmp)) != std::string::npos)
    {
        close++;
        tmp++;
    }
    if (open != close)
        return -1;
    return open;
}

t_arg   *new_core(t_arg  *prev)
{
    t_arg   *tmp = new t_arg;
    Fixed   a;

    tmp->next = NULL;
    tmp->prev = prev;
    tmp->cl = a;
    tmp->del = 0;
    return tmp;
}

std::string     parse(std::string sub)
{
    t_arg   head;
    t_arg   *tmp;
    std::istringstream iss;
    int     cnt_b;
    int     pos;
    std::string     ret;

    cnt_b = 0;
    pos = 0;
    while ((pos = sub.find(' ', pos)) != std::string::npos)
    {
        cnt_b++;
        pos++;
    }
    if (cnt_b % 2)
    {
        std::cerr << "Parse error" << std::endl;
        exit(1);
    }
    iss.str(sub);
    tmp = &head;
    for (int a=0; a<=cnt_b;a+=2)
    {
        tmp->next = new_core(tmp);
        tmp = tmp->next;
        if (a > 0 && !tmp->prev->del)
        {
            std::cerr << "Parse error" << std::endl;
            exit(1);
        }
        iss >> tmp->cl;
        iss >> tmp->del;
        if (!(tmp->del ==  '+' || tmp->del == '-'\
        || tmp->del == '*' || tmp->del == '/'))
            tmp->del = 0;
    }
    ret = get_val(head.next, &head);
    return ret;
}

void    eval_brackets(std::string &arg)
{
    std::string     sub;
    int             open;
    int             close;
    std::string     result;

    close = arg.find(')');
    open = arg.rfind('(', close) + 1;
    sub = arg.substr(open, close - open);
    result = parse(sub);
    arg.replace(open - 1, close - open + 2, result);
}
