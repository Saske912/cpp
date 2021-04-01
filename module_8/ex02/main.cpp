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
// 14.03.2021⠀⠀⠀⠀
//
#include "mutantstack.hpp"
#include <iostream>
#include <list>

int     main( void )
{
//    MutantStack<int> mstack;
//    MutantStack<int>::iterator it = mstack.begin();
//    try {
//        std::cout << *it  << std::endl;
//    }
//    catch (std::exception & e){
//        std::cout << "exception no value"  << std::endl;
//    };
//    mstack.push(5);
//    mstack.push(15);
//    mstack.push(25);
//    mstack.push(27);
////    std::cout << mstack.top()  << std::endl;
//    std::cout << *it  << std::endl;
//    ++it;
//    std::cout << *it  << std::endl;
//    --it;
//    std::cout << *it  << std::endl;
//    try {
//        --it;
//    }
//    catch (std::exception & e){
//        std::cout << "exception no value"  << std::endl;
//    }
//    try {
//        while (1)
//            ++it;
//    }
//    catch (std::exception & e){
//        std::cout << "exception no value"  << std::endl;
//    }
//    MutantStack<int>::iterator ite = mstack.end();
//    std::cout << *ite  << std::endl;
//    try{
//        ++ite;
//    }
//    catch (std::exception & e){
//        std::cout << "exception no value"  << std::endl;
//    }
//    --ite;
//    std::cout << *ite  << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
//[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    MutantStack<std::list<int> >    stac;
    std::list<int> a(4,15);
    std::list<int> b(3,12);
    stac.push(a);
    stac.push(b);
    MutantStack<std::list<int> >::iterator it1 = stac.begin();
    MutantStack<std::list<int> >::iterator ite1 = stac.end();
    while (it1 != ite1)
    {
        for (std::list<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
        {
            std::cout << *it2  << std::endl;
        }
        ++it1;
    }
    return (0);
}