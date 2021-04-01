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
// 07.03.2021⠀⠀⠀⠀
//
#include <iostream>
#include <string>
#include <sstream>

struct Data {
    std::string s1;
    int         n;
    std::string s2;
};

std::string   get_random(const int r)
{
    std::string tmp;
    std::string alpha = "abcdefghijklmnopqrstuvwxyz"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string alphanum = "0123456789"
                                  "abcdefghijklmnopqrstuvwxyz"
                                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand((unsigned )std::time(NULL));
    tmp += alpha[rand() % (alpha.length() - 1)];
    for (int i = 1;i < r;i++)
    {
        tmp += alphanum[rand() % (alphanum.length() - 1)];
    }
    std::stringstream ss;
    ss << rand();
    tmp += ss.str();
    tmp += alpha[rand() % (alpha.length() - 1)];
    for (int i = 1;i < r;i++)
    {
        tmp += alphanum[rand() % (alphanum.length() - 1)];
    }
    return tmp;
}

void*   serialize(void)
{
    std::string tmp;

    tmp = get_random(8);
    std::cout << tmp << std::endl;
    return (void *)tmp.c_str();
}

Data    *deserialize(void *data)
{
    char     *ss;
    std::string temp;
    struct Data     *value = new struct Data;
    ss = static_cast<char*>(data);
    temp = (std::string)ss;
    value->s1 = temp.substr(0,8);
    value->s2 = temp.substr(temp.length() - 8, temp.length() - 1);
    value->n = atoi(temp.substr(8, temp.length() - 8).c_str());
    return value;
}

int     main(void)
{
    void    *data;
    struct Data     *value;

    data = serialize();
    value = deserialize(data);
    std::cout << value->s1 << std::endl;
    std::cout << value->n << std::endl;
    std::cout << value->s2 << std::endl;
    delete value;
    return (0);
}