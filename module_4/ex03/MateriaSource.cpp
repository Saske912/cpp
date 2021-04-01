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
// 28.02.2021⠀⠀⠀⠀
//
#include "MateriaSource.hpp"
#include "header.hpp"

MateriaSource::MateriaSource( void ) : _maxC(4), _cnt(0)
{
    this->_materia.next = 0;
    this->_materia.prev = 0;
    this->_materia.mt = 0;
}

MateriaSource::~MateriaSource( void ) {
    utils::free_squad( this->_materia.next);
}

MateriaSource::MateriaSource( MateriaSource const &src ) : _maxC(4) {
    this->_materia.next = 0;
    this->_materia.prev = 0;
    this->_materia.mt = 0;
    utils::copy_squad( this->_materia, src.getQuad(), src.getCnt());
    this->_cnt = src.getCnt();
}

MateriaSource &MateriaSource::operator=( MateriaSource const &rhs ) {
    utils::free_squad( this->_materia.next);
    utils::copy_squad( this->_materia, rhs.getQuad(), rhs.getCnt());
    this->_cnt = rhs.getCnt();
    return *this;
}

t_quad const    MateriaSource::getQuad() const
{
    return this->_materia;
}

int MateriaSource::getCnt() const
{
    return this->_cnt;
}

void MateriaSource::learnMateria(AMateria* m)
{
    t_quad *tmp;
    int     i;

    if ( this->_cnt == this->_maxC && m)
    {
        delete m;
        return;
    }
    i = 0;
    tmp = &this->_materia;
    while (i < this->_cnt)
    {
        tmp = tmp->next;
        i++;
    }
    tmp->next = utils::new_unit(tmp);
    tmp = tmp->next;
    tmp->mt = m;
    this->_cnt++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    t_quad *tmp;
    int     i;

    i = 0;
    tmp = &this->_materia;
    while (i < this->_cnt)
    {
        tmp = tmp->next;
        i++;
        if (tmp->mt->getType() == type)
            return tmp->mt->clone();
    }
    return 0;
}