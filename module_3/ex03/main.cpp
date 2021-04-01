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
#include "NinjaTrap.hpp"
#include <iostream>

int     main( void )
{
    FragTrap    robot("Va_argE");
    ScavTrap    scav("digit_91");
    NinjaTrap   ninja("Silent assassin");
    NinjaTrap   ninja2("Dark phantom");

    scav.challengeNewcomer("Spider");
    ninja.ninjaShoebox(scav);
    scav.challengeNewcomer("Ninja");
    ninja.ninjaShoebox(robot);
    robot.beRepaired(15);
    ninja.ninjaShoebox(ninja2);
    ninja2.ninjaShoebox(ninja);
    ninja.beRepaired(15);
    ninja.rangedAttack("spider");
    ninja.meleeAttack("Wolf");
    scav.beRepaired(15);
    scav.meleeAttack("Spider");
    scav.rangedAttack("Mouse");
    scav.challengeNewcomer("Dragon");
    scav.challengeNewcomer("Bear");
    scav.takeDamage(25);
    scav.takeDamage(3);
    scav.beRepaired(35);
    scav.takeDamage(45);
    scav.beRepaired(20);
    scav.challengeNewcomer("Dragon");
    scav.challengeNewcomer("Bear");
    scav.challengeNewcomer("Dragon");
    scav.challengeNewcomer("Dragon");
    scav.challengeNewcomer("Dragon");
    robot.beRepaired(15);
    robot.meleeAttack("Spider");
    robot.rangedAttack("Mouse");
    robot.vaultHunter_dot_exe("Dragon");
    robot.vaultHunter_dot_exe("Bear");
    robot.takeDamage(25);
    robot.takeDamage(2);
    robot.takeDamage(5);
    robot.beRepaired(35);
    robot.takeDamage(45);
    robot.beRepaired(20);
    robot.vaultHunter_dot_exe("Dragon");
    robot.vaultHunter_dot_exe("Bear");
    robot.vaultHunter_dot_exe("Dragon");
    robot.vaultHunter_dot_exe("Dragon");
    robot.vaultHunter_dot_exe("Dragon");
    return (0);
}