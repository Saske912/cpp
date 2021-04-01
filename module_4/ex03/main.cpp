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
// 01.03.2021⠀⠀⠀⠀
//
#include "Character.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Fire.hpp"
#include "Earth.hpp"
#include <iostream>

int     main(void)
{
    Character   *mage = new Character("Kadgar");
    AMateria    *ice = new Ice;
    mage->equip(ice);
    Character   *pirest = new Character("Anduin");
    AMateria    *cure = new Cure;
    pirest->equip(cure);
    mage->use(0, *pirest);
    pirest->use(0, *pirest);
    mage->equip(cure);
    mage->use(1, *mage);
    std::cout << "Part1:" << std::endl;
    mage->unequip(0);
    mage->use(0, *mage);
    mage->equip(ice);
    mage->unequip(0);
    mage->use(0, *pirest);
    pirest->equip(ice);
    std::cout << "Part2:" << std::endl;
    pirest->use(0, *mage);
    pirest->use(1, *mage);
    Character   ch1(*pirest);
    pirest->unequip(1);
    pirest->unequip(0);
    delete pirest;
    ch1.use(0, *mage);
    ch1.use(1, *mage);
    std::cout << "Part3:" << std::endl;
    mage->equip(cure);
    mage->use(0, ch1);
    mage->use(1, ch1);
    *mage = ch1;
    mage->use(0, ch1);
    mage->use(1, ch1);
    delete mage;
    std::cout << "Part4:" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "Part4:" << std::endl;
    src->learnMateria(new Fire());
    me->equip(src->createMateria("fire"));
    me->use(2, *bob);
    me->equip(src->createMateria("earth"));
    me->use(3, *bob);
    src->learnMateria(new Earth());
    me->equip(src->createMateria("earth"));
    me->use(3, *bob);
    delete src;
    delete me;
    Character   mag("Kadgar");
    std::cout << "Part5:" << std::endl;
    MateriaSource mat;
    mat.learnMateria(new Earth);
    mat.learnMateria(new Fire);
    mat.learnMateria(new Cure);
    mag.equip(mat.createMateria("cure"));
    tmp = mat.createMateria("fire");
    mag.equip(tmp);
    mag.use(0, *bob);
    MateriaSource mat2(mat);
    mag.equip(mat2.createMateria("ice"));
    mag.equip(mat2.createMateria("cure"));
    mat2.learnMateria(new Earth);
    mat2.learnMateria(new Earth);
    mag.equip(mat2.createMateria("cure"));
    mag.equip(mat2.createMateria("cure"));
    mag.equip(mat2.createMateria("cure"));
    mag.use(1, *bob);
    mat.learnMateria(new Ice);
    mag.equip(mat2.createMateria("ice"));
    mag.use(2, *bob);
    mag.equip(mat.createMateria("ice"));
    mag.use(2, *bob);
    MateriaSource mat3;
    mat3.learnMateria(new Ice);
    mat = mat3;
    mag.equip(mat.createMateria("earth"));
    std::cout << "Part6:" << std::endl;
    mag.use(3, *bob);
    mat.learnMateria(new Earth);
    mag.equip(mat.createMateria("earth"));
    mag.use(3, *bob);
    AMateria *a = new Ice;
    AMateria *b = new Earth;
    AMateria *c = new Fire;
    mat2.learnMateria(a);
    mat2.learnMateria(b);
    mat2.learnMateria(c);
    mag.equip(mat.createMateria("fire"));
    mag.use(3, *bob);
    mag.unequip(1);
    mag.equip(mat2.createMateria("fire"));
    mag.use(3, *bob);
    delete bob;
    delete tmp;
    return (0);
}