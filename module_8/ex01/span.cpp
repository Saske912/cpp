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
// 13.03.2021⠀⠀⠀⠀
//
#include "span.hpp"
#include <exception>
#include <iostream>

Span::Span( unsigned int n) : _max(n), _curr(0)
{
}

Span::Span( void ) {
}

Span::~Span( void ) {
}

unsigned int Span::get_max(void) const
{
    return this->_max;
}

unsigned int Span::get_curr(void) const
{
    return this->_curr;
}

std::list<int> const&  Span::get_ints(void) const
{
    return this->_ints;
}

Span::Span( Span const &src ) {
    this->_ints = src.get_ints();
//    std::copy(src.get_ints().begin(), src.get_ints().end(), _ints.begin());
    this->_max = src.get_max();
    this->_curr = src.get_curr();
}

Span &Span::operator=( Span const &rhs ) {
    _ints.assign(rhs.get_ints().begin(), rhs.get_ints().end());
    this->_max = rhs.get_max();
    this->_curr = rhs.get_curr();
    return *this;
}

void    Span::addNumber(int nb)
{
    if ( this->_curr == this->_max)
        throw std::exception();
    this->_ints.push_back(nb);
    this->_curr++;
}

void    Span::addRandomNumbers(unsigned int n)
{
    for (int i = 0;i < (int)n;i++)
    {
        srand(std::time(NULL) * i);
        int tmp = rand();
        this->addNumber(tmp);
    }
}

unsigned int Span::shortestSpan(void)
{
    unsigned int     span = std::numeric_limits<unsigned int>::max();
    int     tmp;
    _ints.sort();
    if (_ints.size() == 0 || _ints.size() == 1)
        return 0;
    for (std::list<int>::iterator it = this->_ints.begin();it != this->_ints.end();it++)
    {
        if (!tmp)
            tmp = *it;
        else if (tmp == *it)
            return 0;
        else if (span > static_cast<unsigned int>(std::labs((long int)tmp - (long int)*it)))
        {
            span = static_cast<unsigned int>(std::labs((long int)tmp - (long int)*it));
            tmp = *it;
        }
    }
    return span;
}

unsigned int Span::longestSpan(void)
{
    unsigned int     span;

    if (_ints.size() == 0 || _ints.size() == 1)
        return 0;
    int     tmpA = *std::max_element(_ints.begin(), _ints.end());
    int     tmpB = *std::min_element(_ints.begin(), _ints.end());
    span = static_cast<unsigned int>(std::labs((long int)tmpA - (long int)tmpB));
    return span;
}