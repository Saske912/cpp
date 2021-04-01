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
#include "Character.hpp"
#include "header.hpp"
#include <iostream>

Character::Character( void ) : _countMax(4) {
}

Character::Character(std::string name) : _name(name), _countMax(4)
{
    this->_count = 0;
    this->_materia.mt = 0;
    this->_materia.next = 0;
}

Character::~Character( void ) {
    utils::free_squad( this->_materia.next);
}

Character::Character( Character const &src ) : _countMax(4) {
    this->_materia.next = 0;
    this->_materia.mt = 0;
    utils::copy_squad( this->_materia, src.getQuad(), src.getCount());
    this->_count = src.getCount();
    this->_name = src.getName();
}

Character &Character::operator=( Character const &rhs ) {
    utils::free_squad( this->_materia.next);
    utils::copy_squad( this->_materia, rhs.getQuad(), rhs.getCount());
    this->_count = rhs.getCount();
    this->_name = rhs.getName();
    return *this;
}

t_quad  Character::getQuad() const
{
    return this->_materia;
}

std::string const & Character::getName() const
{
    return this->_name;
}

int     Character::getCount() const
{
    return this->_count;
}

void    Character::equip(AMateria* m)
{
    t_quad *tmp;
    int     i;

    if (!m)
        return;
    if ( this->_count == this->_countMax)
    {
        delete m;
        return;
    }
    i = 0;
    tmp = &this->_materia;
    while (i < this->_count)
    {
        tmp = tmp->next;
        i++;
    }
    tmp->next = utils::new_unit(tmp);
    tmp = tmp->next;
    tmp->mt = m;
    this->_count++;
}

void    Character::unequip(int idx)
{
    t_quad *tmp;

    tmp = utils::getQuad(idx, this->_materia.next, this->_count);
    tmp->mt = 0;
    if (tmp->next)
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    else
        tmp->prev->next = 0;
    delete tmp;
    this->_count--;
}

void    Character::use(int idx, ICharacter& target)
{
    t_quad *tmp;

    if (idx >= this->_count)
        return;
    tmp = utils::getQuad(idx, this->_materia.next, this->_count);
    tmp->mt->use(target);
}