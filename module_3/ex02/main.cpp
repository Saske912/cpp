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
#include "ScavTrap.hpp"
#include <iostream>

int     main( void )
{
    FragTrap    *robot = new FragTrap("Va_argE");
    ScavTrap    *scav = new ScavTrap("digit_91");

    scav->beRepaired(15);
    scav->meleeAttack("Spider");
    scav->rangedAttack("Mouse");
    scav->challengeNewcomer("Dragon");
    scav->challengeNewcomer("Bear");
    scav->takeDamage(25);
    scav->takeDamage(3);
    scav->beRepaired(35);
    scav->takeDamage(45);
    scav->beRepaired(20);
    scav->challengeNewcomer("Dragon");
    scav->challengeNewcomer("Bear");
    scav->challengeNewcomer("Dragon");
    scav->challengeNewcomer("Dragon");
    scav->challengeNewcomer("Dragon");
    if (scav->takeDamage(110) == 1)
        delete scav;
    robot->beRepaired(15);
    robot->meleeAttack("Spider");
    robot->rangedAttack("Mouse");
    robot->vaultHunter_dot_exe("Dragon");
    robot->vaultHunter_dot_exe("Bear");
    robot->takeDamage(25);
    robot->takeDamage(2);
    robot->takeDamage(5);
    robot->beRepaired(35);
    robot->takeDamage(45);
    robot->beRepaired(20);
    robot->vaultHunter_dot_exe("Dragon");
    robot->vaultHunter_dot_exe("Bear");
    robot->vaultHunter_dot_exe("Dragon");
    robot->vaultHunter_dot_exe("Dragon");
    robot->vaultHunter_dot_exe("Dragon");
    if (robot->takeDamage(85) == 1)
        delete robot;


    return (0);
}