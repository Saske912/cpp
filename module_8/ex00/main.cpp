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
// 12.03.2021⠀⠀⠀⠀
//
#include "easyfind.hpp"
#include <list>
#include <map>
#include <vector>
#include <deque>

int     main( void )
{
    int ints[] = {16,2,77,29};
    double doubles[] = {0.25, 52.13};
    std::list<int> a(ints, ints + sizeof(ints)/sizeof(int));
    std::vector<int> b(ints, ints + sizeof(ints)/sizeof(int));
    std::map<char, int> c;

    c['a'] = ints[0];
    c['b'] = ints[1];
    c['c'] = ints[2];
    c['d'] = ints[3];
    std::map<std::string, int> d;
    d["str"] = ints[0];
    d["str1"] = ints[1];
    d["str2"] = ints[2];
    d["str3"] = ints[3];
    std::deque<int> e(ints, ints + sizeof(ints)/sizeof(int));
    std::map<std::string, char> f;
    f["str"] = 'a';
    f["str1"] = 'b';
    f["str2"] = 'c';
    f["str3"] = 'd';
    std::list<double> g(doubles, doubles + sizeof(doubles )/sizeof(double ));
    int     val;
    std::cout << "\x1b[1m""List:""\x1b[0m"  << std::endl;
    try {
        val = easyfind(a, 5);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error no value" << std::endl;
    }
    try {
        val = easyfind(a, 77);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error no value" << std::endl;
    }
    try {
        val = easyfind(a, 29);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error no value" << std::endl;
    }
    try {
        val = easyfind(g, 29);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error no value" << std::endl;
    }
    std::cout << "\x1b[1m""Vector:""\x1b[0m" << std::endl;
    try {
        val = easyfind(b, 29);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error no value" << std::endl;
    }
    try {
        val = easyfind(b, 5);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error no value" << std::endl;
    }
    std::cout << "\x1b[1m""Map:""\x1b[0m" << std::endl;
    try {
        val = easyfind(c, 5);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: no value" << std::endl;
    }
    try {
        val = easyfind(c, 29);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: no value" << std::endl;
    }
    try {
        val = easyfind(d, 5);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: no value" << std::endl;
    }
    try {
        val = easyfind(d, 29);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: no value" << std::endl;
    }
    try {
        val = easyfind(f, 29);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: no value" << std::endl;
    }
    std::cout << "\x1b[1m""Deque:""\x1b[0m"  << std::endl;
    try {
        val = easyfind(e, 5);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: no value" << std::endl;
    }
    try {
        val = easyfind(e, 77);
        std::cout << val  << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: no value" << std::endl;
    }
    return (0);
}