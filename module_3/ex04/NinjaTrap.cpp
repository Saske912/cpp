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
#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap( void ) {
    this->_name = "default_ninja";
    this->_max_energy_points = 120;
    this->_energy_points = this->_max_energy_points;
    this->_level = 1;
    this->_melee_attack_damage = 60;
    std::cout << "Helloooo, im Ninja!" << std::endl;
}

NinjaTrap::NinjaTrap( std::string name ) {
    this->_name = name;
    this->_max_energy_points = 120;
    this->_max_hit_points = 60;
    this->_hit_points = this->_max_hit_points;
    this->_energy_points = this->_max_energy_points;
    this->_level = 1;
    this->_armor_damage_reduction = 0;
    this->_melee_attack_damage = 60;
    this->_ranged_attack_damage = 5;
    std::cout << "Helloooo, im Ninja!" << std::endl;
}

NinjaTrap::~NinjaTrap( void ) {
    std::cout << "Ninja is dead!" << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const &src ) {
    *this = src;
}

NinjaTrap &NinjaTrap::operator=( NinjaTrap const &rhs ) {
    this->_name = rhs._name;
    return *this;
}

void    NinjaTrap::rangedAttack(std::string const & target)
{
    std::cout << "Ninja " << this->_name << " threw a shuriken ";
    std::cout << target << " at range, causing " << this->_ranged_attack_damage;
    std::cout << " points of damage." << std::endl;
}

void    NinjaTrap::meleeAttack(std::string const & target)
{
    std::cout << "Ninja " << this->_name << " hit by katana ";
    std::cout << target << " at melee, causing " << this->_melee_attack_damage;
    std::cout << " points of damage." << std::endl;
}

void    NinjaTrap::ninjaShoebox(ScavTrap & target)
{
    if ( this->_energy_points > 49)
    {
        target.set_energy(0);
        this->_energy_points -= 50;
        std::cout << "Ninja power off door energy" << std::endl;
    }
    else
        std::cout << "Ninja " << this->_name << " have not enough energy" << std::endl;
}

void    NinjaTrap::ninjaShoebox(FragTrap & target)
{
    if ( this->_energy_points > 69)
    {
        target.set_health(55);
        this->_energy_points -= 70;
        std::cout << "Ninja: now i can kill this Frag by next strike!" << std::endl;
    }
    else
        std::cout << "Ninja " << this->_name << " have not enough energy" << std::endl;
}

void    NinjaTrap::ninjaShoebox(NinjaTrap  &target)
{
    if ( this->_energy_points > 29)
    {
        this->_energy_points -= 30;
        std::cout << "Ninja " << this->_name << " awasome kicked other ninja!" << std::endl;
        target.set_health(10);
        target.set_energy(10);
    }
    else
        std::cout << "Ninja " << this->_name << " have not enough energy." << std::endl;
}