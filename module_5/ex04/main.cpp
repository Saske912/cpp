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
// 02.03.2021⠀⠀⠀⠀
//

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int     main(void)
{
    Bureaucrat  *bur1;
    Bureaucrat  *bur2;
    try {
        bur1 = new Bureaucrat("Vasia", 5);
        std::cout << *bur1;
    }
    catch (std::exception & e)
    {}
    Intern  *intern = new Intern;
    try {
        bur2 = new Bureaucrat("Peter", 80);
        std::cout << *bur2;
    }
    catch (std::exception & e)
    {}
    OfficeBlock *office;
    office = new OfficeBlock(*intern, *bur1, *bur2);
    try {
        office->doBureaucracy("robot request", "campus");
    }
    catch (std::exception & e)
    {}
    try {
        office->doBureaucracy("robotomy request", "campus");
    }
    catch (std::exception & e)
    {}
    Bureaucrat  *bur3;
    try {
        bur3 = new Bureaucrat("Peter", 45);
        std::cout << *bur3;
    }
    catch (std::exception & e)
    {}
    office->setExecuting(*bur3);
    try {
        office->doBureaucracy("robotomy request", "campus");
    }
    catch (std::exception & e)
    {}
    delete intern;
    delete bur3;
    delete office;
    delete bur1;
    delete bur2;
    Intern idiotOne;
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
    OfficeBlock ob;
    ob.setIntern(idiotOne);
    ob.setSigning(bob);
//    ob.setExecuting(hermes);
    try
    {
        ob.doBureaucracy("shrubbery creation", "Pigley");
    }
    catch (OfficeBlock::Error & e)
    {
        std::cout  << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
/* oh god, unknown error, what to do ?! */
    }
}
