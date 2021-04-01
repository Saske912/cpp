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
// 25.02.2021⠀⠀⠀⠀
//
#include "ScavTrap.hpp"
#include <iostream>

unsigned int ScavTrap::_vault_hunt = 0;

ScavTrap::ScavTrap( void ) : _name("default_scav"){
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_level = 1;
    this->max_energy_points = 50;
    this->max_hit_points = 100;
    this->armor_damage_reduction = 3;
    this->melee_attack_damage = 20;
    this->ranged_attack_damage = 15;
    std::cout << "Helloooo, im Scav!" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : _name(name)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_level = 1;
    this->max_energy_points = 50;
    this->max_hit_points = 100;
    this->armor_damage_reduction = 3;
    this->melee_attack_damage = 20;
    this->ranged_attack_damage = 15;
    std::cout << "Helloooo, im Scav!" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "Scav is gone..." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src ) {
    *this = src;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &rhs ) {
    this->_name = rhs._name;
    return *this;
}

void    ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "Scav " << this->_name << " soo new incomer and smash ";
    std::cout << target << " at range, causing " << this->ranged_attack_damage;
    std::cout << " points of damage." << std::endl;
}

void    ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "Scav " << this->_name << " soo new incomer and hit ";
    std::cout << target << " at melee, causing " << this->melee_attack_damage;
    std::cout << " points of damage." << std::endl;
}

int    ScavTrap::takeDamage( unsigned int damage )
{
    unsigned int     differ;

    if (damage > this->armor_damage_reduction)
    {
        differ = damage - this->armor_damage_reduction;
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

void    ScavTrap::beRepaired( unsigned int repair )
{
    unsigned int diff_hp;
    unsigned int diff_energy;

    if ( this->_hit_points == this->max_hit_points)
    {
        std::cout << "FR4G-TP " << this->_name << " already have maximum health. ";
    }
    else if ( this->_hit_points + repair > this->max_hit_points)
    {
        diff_hp = this->max_hit_points - this->_hit_points;
        this->_hit_points = this->max_hit_points;
        std::cout << "FR4G-TP " << this->_name << " restored " << diff_hp;
        std::cout << " hp, now he has maximum " << this->_hit_points << " health! ";
    }
    else
    {
        this->_hit_points += repair;
        std::cout << "FR4G-TP " << this->_name << " restored " << repair;
        std::cout << " hp, now he has " << this->_hit_points << " health! ";
    }
    if ( this->_energy_points == this->max_energy_points)
    {
        std::cout << "FR4G-TP " << this->_name << " already have maximum energy." << std::endl;
    }
    else if ( this->_energy_points + repair > this->max_energy_points)
    {
        diff_energy = this->max_energy_points - this->_energy_points;
        this->_energy_points = this->max_energy_points;
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

void    ScavTrap::challengeNewcomer(std::string const & target)
{
    std::string     tmp;

    if ( this->_energy_points > 9)
    {
        this->_energy_points -= 10;
        switch ( this->_vault_hunt) {
            case 0:
                tmp = "Electric water";
                break ;
            case 1:
                tmp = "Death cloud";
                break ;
            case 2:
                tmp = "Ice ceil";
                break ;
            case 3:
                tmp = "Dementia gaze";
                break ;
            case 4:
                tmp = "Branch kick";
        }
        if ( this->_vault_hunt == 4)
            this->_vault_hunt = 0;
        else
            this->_vault_hunt++;
        std::cout << "Scav " << this->_name << " attacks " << target;
        std::cout << " with " << tmp << "! Now he has " << this->_energy_points;
        std::cout << " energy. Now he's level " << ++this->_level << std::endl;
    }
    else
    {
        std::cout << "Scav " << this->_name << " hasn't enough energy!" << std::endl;
    }
}