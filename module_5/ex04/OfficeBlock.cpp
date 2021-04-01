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
// 05.03.2021⠀⠀⠀⠀
//
#include "OfficeBlock.hpp"
#include <iostream>

OfficeBlock::OfficeBlock( void ) {
    this->_bur1 = 0;
    this->_bur2 = 0;
    this->_intern = 0;
}

OfficeBlock::~OfficeBlock( void ) {
}

OfficeBlock::OfficeBlock( Intern & intern, \
Bureaucrat & bur1, Bureaucrat & bur2)
{
    this->_intern = &intern;
    this->_bur1 = &bur1;
    this->_bur2 = &bur2;
}

void    OfficeBlock::doBureaucracy(std::string name, std::string target)
{
    Form    *tmp;

    if ( this->_intern && this->_bur1 && this->_bur2)
    {
        try {
            tmp = this->_intern->makeForm(name, target);
        }
        catch (std::exception &e)
        {
            throw std::exception();
        }
        try {
            this->_bur1->signForm(*tmp);
        }
        catch (std::exception & e)
        {
            delete tmp;
            throw std::exception();
        }
        try {
            this->_bur2->executeFrom(*tmp);
        }
        catch (std::exception & e)
        {
            delete tmp;
            throw std::exception();
        }
        delete tmp;
    }
    else
    {
        throw OfficeBlock::Error();
    }
}

void    OfficeBlock::setIntern(Intern &intern)
{
    this->_intern = &intern;
}

void    OfficeBlock::setSigning(Bureaucrat &bureaucrat)
{
    this->_bur1 = &bureaucrat;
}

void    OfficeBlock::setExecuting(Bureaucrat &bureaucrat)
{
    this->_bur2 = &bureaucrat;
}

const char *    OfficeBlock::Error::what() const throw()
{
    return ("Office is incomplete");
}