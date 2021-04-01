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
#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap( void ) : NinjaTrap(), FragTrap() {
    this->_name = "Default SuperTrap";
    this->_hit_points =  FragTrap::_hit_points;
    this->_max_hit_points = FragTrap::_max_hit_points;
    this->_energy_points = NinjaTrap::_energy_points;
    this->_max_energy_points = NinjaTrap::_max_energy_points;
    this->_level = 1;
    this->_melee_attack_damage = NinjaTrap::_melee_attack_damage;
    this->_ranged_attack_damage = FragTrap::_ranged_attack_damage;
    this->_armor_damage_reduction = FragTrap::_armor_damage_reduction;
}

SuperTrap::SuperTrap( std::string name ) : NinjaTrap(), FragTrap()
{
    this->FragTrap::_name = name;
    this->_hit_points =  this->FragTrap::_hit_points;
    this->_max_hit_points = this->FragTrap::_max_hit_points;
    this->_energy_points = this->NinjaTrap::_energy_points;
    this->_max_energy_points = this->NinjaTrap::_max_energy_points;
    this->_level = 1;
    this->_melee_attack_damage = this->NinjaTrap::_melee_attack_damage;
    this->_ranged_attack_damage = this->FragTrap::_ranged_attack_damage;
    this->_armor_damage_reduction = this->FragTrap::_armor_damage_reduction;
    std::cout << "Super builder" << std::endl;
}

SuperTrap::~SuperTrap( void ) {
    std::cout << "Super destroyer" << std::endl;
}

SuperTrap::SuperTrap( SuperTrap const &src ) {
    *this = src;
}

SuperTrap &SuperTrap::operator=( SuperTrap const &rhs ) {
    this->FragTrap::_name = rhs.FragTrap::_name;
    return *this;
}

void    SuperTrap::rangedAttack(std::string const & target)
{
    FragTrap::rangedAttack(target);
}

void    SuperTrap::meleeAttack(std::string const & target)
{
    NinjaTrap::meleeAttack(target);
}