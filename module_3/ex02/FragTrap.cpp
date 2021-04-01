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
#include "FragTrap.h"
#include <string>
#include <iostream>

FragTrap::FragTrap( void )
{
    this->_name = "default";
    this->_energy_points = 100;
    this->_level = 1;
    this->_max_energy_points = 100;
    this->_armor_damage_reduction = 5;
    this->_melee_attack_damage = 30;
    this->_ranged_attack_damage = 20;
    std::cout << "Helloooo, digitized traveler!" << std::endl;
}

FragTrap::~FragTrap( void ) {
    std::cout << "Good bye, traveler!" << std::endl;
}

FragTrap::FragTrap( FragTrap const &src ) {
    *this = src;
}

FragTrap &FragTrap::operator=( FragTrap const &rhs ) {
    this->_name = rhs._name;
    return *this;
}

FragTrap::FragTrap( std::string name )
{
    this->_name = name;
    this->_energy_points = 100;
    this->_level = 1;
    this->_max_energy_points = 100;
    this->_armor_damage_reduction = 5;
    this->_melee_attack_damage = 30;
    this->_ranged_attack_damage = 20;
    std::cout << "Helloooo, digitized traveler!" << std::endl;
}

void    FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks ";
    std::cout << target << " at range, causing " << this->_ranged_attack_damage;
    std::cout << " points of damage!" << std::endl;
}

void    FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks ";
    std::cout << target << " at melee, causing " << this->_melee_attack_damage;
    std::cout << " points of damage!" << std::endl;
}

void    FragTrap::vaultHunter_dot_exe(std::string const & target)
{
    std::string     tmp;

    if ( this->_energy_points > 24)
    {
        this->_energy_points -= 25;
        switch ( this->_vault_hunt) {
            case 0:
                tmp = "Boulder smash";
                break ;
            case 1:
                tmp = "Buckler strike";
                break ;
            case 2:
                tmp = "Midnight arrow";
                break ;
            case 3:
                tmp = "Electric shock";
                break ;
            case 4:
                tmp = "Superman kick";
                break ;
        }
        if ( this->_vault_hunt == 4)
        {
            this->_vault_hunt = 0;
        }
        else
            this->_vault_hunt++;
        std::cout << "FR4G-TP " << this->_name << " attacks " << target;
        std::cout << " with " << tmp << "! Now he has " << this->_energy_points;
        std::cout << " energy. Now he's level " << ++this->_level << std::endl;
    }
    else
    {
        std::cout << "FR4G-TP " << this->_name << " hasn't enough energy!" << std::endl;
    }
}