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
#include "Form.hpp"
#include <exception>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int     main(void)
{
    Bureaucrat  *bur;
    try {
        bur = new Bureaucrat("Vasia", 140);
        std::cout << *bur;
    }
    catch (std::exception & e)
    {
    }
    Form    *robo = new RobotomyRequestForm("robot_form");
    Form    *pres = new PresidentialPardonForm("president_form");
    Form    *shru = new ShrubberyCreationForm("Shrubbery_form");
    try {
        bur->signForm(*robo);
    }
    catch (std::exception & e)
    {
    }
    try {
        bur->signForm(*pres);
    }
    catch (std::exception & e)
    {
    }
    try {
        bur->signForm(*shru);
    }
    catch (std::exception & e)
    {
    }
    std::cout << *shru;
    try {
        bur->executeFrom(*shru);
    }
    catch (std::exception & e)
    {
    }
    delete bur;
    try {
        bur = new Bureaucrat("Petia", 60);
        std::cout << *bur;
    }
    catch (std::exception & e)
    {
    }
    try {
        bur->executeFrom(*shru);
    }
    catch (std::exception & e)
    {
    }
    try {
        bur->executeFrom(*robo);
    }
    catch (std::exception & e)
    {
    }
    try {
        bur->signForm(*robo);
    }
    catch (std::exception & e)
    {
    }
    try {
        bur->executeFrom(*robo);
    }
    catch (std::exception & e)
    {}
    delete bur;
    try {
        bur = new Bureaucrat("Ivan", 3);
        std::cout << *bur;
    }
    catch (std::exception & e)
    {}
    try {
        bur->executeFrom(*robo);
    }
    catch (std::exception & e)
    {}
    try {
        bur->signForm(*pres);
    }
    catch (std::exception & e)
    {}

    try {
        bur->executeFrom(*pres);
    }
    catch (std::exception & e)
    {}
    delete robo;
    delete shru;
    delete pres;
    delete bur;
}
