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

#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include "DesertWolf.hpp"
#include "ElectricWave.hpp"
#include "ForestBandit.hpp"
#include "HydroKnife.hpp"
#include <iostream>

int     main(void)
{
//    PlasmaRifle r1;
//    PowerFist   p1;
//    SuperMutant m1;
//    RadScorpion rad1;
//
//    r1.attack();
//    p1.attack();
//    m1.takeDamage(15);
//    std::cout << m1.getHP() << " " << m1.getType() << std::endl;
//    m1.takeDamage(2);
//    std::cout << m1.getHP() << " " << m1.getType()  << std::endl;
//    rad1.takeDamage(15);
//    std::cout << rad1.getHP() << " " << rad1.getType() << std::endl;
    Character* me = new Character("me");
    std::cout << *me;
    Enemy* b = new RadScorpion();
    me->attack(b);
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    me->equip(pr);
    std::cout << *me;
    me->equip(pf);
    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    DesertWolf* wf = new DesertWolf();
    me->attack(wf);
    ElectricWave* ew = new ElectricWave();
    me->equip(ew);
    me->attack(wf);
    me->attack(wf);
    me->attack(wf);
    std::cout << *me;
    ForestBandit   *b1 = new ForestBandit();
    me->attack(b1);
    me->attack(b1);
    me->recoverAP();
    me->recoverAP();
    ForestBandit *b2 = new ForestBandit();
    *b2 = *b1;
    HydroKnife  *kz1 = new HydroKnife();
    me->equip(kz1);
    std::cout << *me;
    me->attack(b2);
    me->attack(b1);
    me->recoverAP();
    me->recoverAP();
    me->recoverAP();
    std::cout << *me;
    me->recoverAP();
    std::cout << *me;
    delete me;
    delete pr;
    delete pf;
    delete ew;
    delete kz1;
    return (0);
}