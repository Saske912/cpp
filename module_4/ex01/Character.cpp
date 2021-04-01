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
// 27.02.2021⠀⠀⠀⠀
//
#include "Character.hpp"
#include <iostream>

Character::Character( void ) : _maxAP(40)
{
    this->_weapon = NULL;
}

Character::Character( std::string const & name ) : _name(name), _maxAP(40)
{
    this->_weapon = NULL;
    this->_AP = this->_maxAP;
}

Character::~Character( void ) {
}

Character::Character( Character const &src ) {
    *this = src;
}

std::string const Character::getName() const
{
    return this->_name;
}

void    Character::setName( const std::string name )
{
    this->_name = name;
}

Character &Character::operator=( Character const &rhs ) {
    this->setName(rhs.getName());
    return *this;
}

void    Character::recoverAP( )
{
    if ( this->_AP + 10 > this->_maxAP)
        this->_AP = this->_maxAP;
    else
        this->_AP += 10;
}

void    Character::equip( AWeapon *weapon )
{
    this->_weapon = weapon;
}

void    Character::attack( Enemy *enemy )
{
    if ( enemy && this->_weapon && this->_AP >= this->_weapon->getAPCost())
    {
        this->_AP -= this->_weapon->getAPCost();
        enemy->takeDamage(_weapon->getDamage());
        std::cout << this->getName() << " attacks " << enemy->getType();
        std::cout << " with a " << this->_weapon->getName() << std::endl;
        this->_weapon->attack();
        if (enemy->getHP() <= 0)
        {
            delete enemy;
        }
    }
}

int     Character::getAP() const
{
    return this->_AP;
}

std::ostream &      operator<<(std::ostream & o, Character const & character)
{
    if (character._weapon)
    {
        o << character.getName() << " has " << character.getAP();
        o << " AP and wields a " << character._weapon->getName() << std::endl;
    }
    else
    {
        o << character.getName() << " has " << character.getAP();
        o << " AP and is unarmed" << std::endl;
    }
    return o;
}