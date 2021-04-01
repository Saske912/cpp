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
// 28.02.2021⠀⠀⠀⠀
//
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

t_quad  *new_unit()
{
    t_quad *tmp;

    tmp = new t_quad;
    tmp->next = 0;
    tmp->unit = 0;
    return tmp;
}

void    copy_squad(t_quad &q1, t_quad const &q2, int count)
{
    t_quad *tmp1;
    t_quad *tmp2;
    int    i;

    i = 0;
    tmp2 = q2.next;
    tmp1 = &q1;
    while (i < count)
    {
        tmp1->next = new_unit();
        tmp1 = tmp1->next;
        tmp1->unit = tmp2->unit->clone();
        i++;
        tmp2 = tmp2->next;
    }
}

void    free_squad(t_quad *core)

{
    t_quad *tmp;
    t_quad *copy;

    tmp = core;
    while (tmp)
    {
        copy = tmp->next;
        delete tmp->unit;
        delete tmp;
        tmp = copy;
    }
}

Squad::Squad( void ) : _count(0)
{
    this->_squad.next = 0;
    this->_squad.unit = 0;
}

Squad::~Squad( void ) {
    free_squad( this->_squad.next);
}

Squad::Squad( Squad const &src ) {
    copy_squad( this->_squad, src._squad, src._count);
    this->_count = src._count;
}

Squad &Squad::operator=( Squad const &rhs ) {
    free_squad( this->_squad.next);
    copy_squad( this->_squad, rhs._squad, rhs._count);
    this->_count = rhs._count;
    return *this;
}

int Squad::getCount() const
{
    return this->_count;
}

int Squad::push(ISpaceMarine* marine)
{
    t_quad *tmp;
    int     i;

    i = 0;
    tmp = &this->_squad;
    while (i < this->_count)
    {
        tmp = tmp->next;
        i++;
    }
    tmp->next = new_unit();
    tmp = tmp->next;
    tmp->unit = marine;
    this->_count++;
    return ++i;
}

ISpaceMarine* Squad::getUnit(int unit) const
{
    int     i;
    t_quad const  *tmp;

    if (unit > this->_count)
        return 0;
    i = 0;
    tmp = &this->_squad;
    while (i <= unit)
    {
        tmp = tmp->next;
        i++;
    }
    return tmp->unit;
}
