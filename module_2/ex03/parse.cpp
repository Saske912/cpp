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
// 24.02.2021⠀⠀⠀⠀
//

#include "header.h"
#include "Fixed.hpp"
#include <string>
#include <sstream>

t_arg*   switch_core(t_arg *core)
{
    t_arg   *tmp;

    core->next->prev = core->prev;
    core->prev->next = core->next;
    tmp = core->next;
    delete core;
    core = tmp;
    return core;
}

std::string     get_val(t_arg *core, t_arg *head)
{
    t_arg   *tmp;
    int     ci;

    ci = 0;
    while (core->next)
    {
        switch (core->del) {
            case '*':
                core->next->cl = core->cl * core->next->cl;
                core = switch_core(core);
                break;
            case '/':
                core->next->cl = core->cl / core->next->cl;
                core = switch_core(core);
                break;
            case '+':
                if (core->next->del != '*' && core->next->del != '/')
                {
                    core->next->cl = core->cl + core->next->cl;
                    core = switch_core(core);
                    break;
                }
                else
                {
                    core = core->next;
                    ci = 1;
                    break;
                }
            case '-':
                if (core->next->del != '*' && core->next->del != '/')
                {
                    core->next->cl = core->cl - core->next->cl;
                    core = switch_core(core);
                    break;
                }
                else
                {
                    core = core->next;
                    ci = 1;
                    break;
                }
        }
    }
    tmp = head->next;
    if (ci)
    {
        while(tmp->next)
        {
            if (tmp->del == '+')
            {
                tmp->next->cl = tmp->cl + tmp->next->cl;
                tmp = switch_core(tmp);
            }
            else
            {
                tmp->next->cl = tmp->cl - tmp->next->cl;
                tmp = switch_core(tmp);
            }
        }
    }
    std::ostringstream ss;
    ss << tmp->cl.toFloat();
    std::string ret(ss.str());
    delete tmp;
    return ret;
}