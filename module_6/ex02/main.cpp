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
#include "B.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "C.hpp"
#include <iostream>

Base    *generate(void)
{
    Base    *tmp[3];
    int     c;
    Base    *ret;

    srand((unsigned )std::time(NULL));
    tmp[0] = new A;
    tmp[1] = new B;
    tmp[2] = new C;
    ret = tmp[(c = rand() % 3)];
    for (int i = 0;i < 3;i++)
        if (i != c)
            delete tmp[i];
    return ret;
}

void    identify_from_reference(Base & p)
{
    A   a;
    B   b;
    C   c;

    try {
        a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast & bc)
    {}
    try {
        b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast & bc)
    {}
    try {
        c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast & bc)
    {}
}

void    identify_from_pointer(Base * p)
{
    A   *a;
    B   *b;
    C   *c;

    a = dynamic_cast<A *>(p);
    if (a)
        std::cout << "A" << std::endl;
    b = dynamic_cast<B *>(p);
    if (b)
        std::cout << "B" << std::endl;
    c = dynamic_cast<C *>(p);
    if (c)
        std::cout << "C" << std::endl;
}

int     main(void)
{
    Base    *tmp;
    tmp = generate();
    identify_from_pointer(tmp);
    identify_from_reference(*tmp);
    delete tmp;
}