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
// 26.02.2021⠀⠀⠀⠀
//
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) {
    this->_vault_hunt = 0;
    this->_max_hit_points = 100;
    this->_hit_points = this->_max_hit_points;
    std::cout << "Default clap builder" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "Default clap destroyer" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &src ) {
    *this = src;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs ) {
    this->_name = rhs._name;
    return *this;
}

int    ClapTrap::takeDamage( unsigned int damage )
{
    unsigned int     differ;

    if (damage > this->_armor_damage_reduction)
    {
        differ = damage - this->_armor_damage_reduction;
        std::cout << "FR4G-TP " << this->_name << " was attacked and causing ";
        std::cout << differ << " points of damage!";
        if ( this->_hit_points > differ)
        {
            this->_hit_points -= differ;
            std::cout << " Now he have " << this->_hit_points << " health points" << std::endl;
        }
        else
        {
            std::cout << " This was a lethal damage" << std::endl;
            return (1);
        }
    }
    else
    {
        std::cout << "FR4G-TP " << this->_name << " avoid damage!" << std::endl;
    }
    return (0);
}

void    ClapTrap::beRepaired( unsigned int repair )
{
    unsigned int diff_hp;
    unsigned int diff_energy;

    if ( this->_hit_points == this->_max_hit_points)
    {
        std::cout << "FR4G-TP " << this->_name << " already have maximum health. ";
    }
    else if ( this->_hit_points + repair > this->_max_hit_points)
    {
        diff_hp = this->_max_hit_points - this->_hit_points;
        this->_hit_points = this->_max_hit_points;
        std::cout << "FR4G-TP " << this->_name << " restored " << diff_hp;
        std::cout << " hp, now he has maximum " << this->_hit_points << " health! ";
    }
    else
    {
        this->_hit_points += repair;
        std::cout << "FR4G-TP " << this->_name << " restored " << repair;
        std::cout << " hp, now he has " << this->_hit_points << " health! ";
    }
    if ( this->_energy_points == this->_max_energy_points)
    {
        std::cout << "FR4G-TP " << this->_name << " already have maximum energy." << std::endl;
    }
    else if ( this->_energy_points + repair > this->_max_energy_points)
    {
        diff_energy = this->_max_energy_points - this->_energy_points;
        this->_energy_points = this->_max_energy_points;
        std::cout << "FR4G-TP " << this->_name << " restored " << diff_energy;
        std::cout << " energy, now he has maximum " << this->_energy_points << " energy!" << std::endl;
    }
    else
    {
        this->_energy_points += repair;
        std::cout << "FR4G-TP " << this->_name << " restored " << repair;
        std::cout << " energy, now he has " << this->_energy_points << " energy!" << std::endl;
    }
}