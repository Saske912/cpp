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

ScavTrap::ScavTrap( void ) {
    this->_name = "default_scav";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_level = 1;
    this->_max_energy_points = 50;
    this->_max_hit_points = 100;
    this->_armor_damage_reduction = 3;
    this->_melee_attack_damage = 20;
    this->_ranged_attack_damage = 15;
    std::cout << "Helloooo, im Scav!" << std::endl;
}

ScavTrap::ScavTrap( std::string name )
{
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_level = 1;
    this->_max_energy_points = 50;
    this->_max_hit_points = 100;
    this->_armor_damage_reduction = 3;
    this->_melee_attack_damage = 20;
    this->_ranged_attack_damage = 15;
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
    std::cout << target << " at range, causing " << this->_ranged_attack_damage;
    std::cout << " points of damage." << std::endl;
}

void    ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "Scav " << this->_name << " soo new incomer and hit ";
    std::cout << target << " at melee, causing " << this->_melee_attack_damage;
    std::cout << " points of damage." << std::endl;
}

void    ScavTrap::challengeNewcomer(std::string const & target)
{
    std::string     tmp;

    if ( this->_energy_points > 24)
    {
        this->_energy_points -= 25;
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