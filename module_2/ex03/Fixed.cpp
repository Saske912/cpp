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
// 20.02.2021⠀⠀⠀⠀
//
#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

Fixed::Fixed( void ) : _point(0)
{
}

Fixed::~Fixed( void )
{
}

Fixed::Fixed( Fixed const &src )
{
    *this = src;
}

Fixed &Fixed::operator=( Fixed const &rhs )
{
    this->_point = rhs.getRawBits();
    return *this;
}

int     Fixed::getRawBits( void ) const
{
    return this->_point;
}

void    Fixed::SetRawBits( int const raw )
{
    this->_point = raw;
}

Fixed::Fixed( int const val )
{
    SetRawBits(val << this->_val);
}

Fixed::Fixed( float const val )
{
    int   tmpA;
    int   tmpB;

    tmpA = (int(val) << this->_val);
//    std::cout << (tmpA >> 8) << " " << std::bitset<32>(tmpA) << std::endl;
    tmpB = int((val - int(val)) * (1 << this->_val));
//    std::cout << tmpB << " " << std::bitset<32>(tmpB) << std::endl;
    this->SetRawBits(tmpA | tmpB);
//    std::cout << std::bitset<32>(this->_point) << std::endl;
}

float   Fixed::toFloat( void ) const
{
    float   tmp;
    int     tmpA;
    float   tmpB;

//    std::cout << "toFloat called" << std::endl;
//    std::cout << std::bitset<32>(this->_point) << std::endl;
    tmpA = float(this->_point >> this->_val);
//    std::cout << std::bitset<32>(tmpA) << std::endl;
//    std::cout << "tmpA " << tmpA << std::endl;
    tmpB = float(this->_point & 0xFF);
//    std::cout << "tmpB " << tmpB << std::endl;
//    std::cout << std::bitset<32>(tmpB) << std::endl;
    tmp = tmpA + tmpB / (1 << this->_val);
//    std::cout << std::bitset<32>(this->_point) << std::endl;
    return tmp;
}

int   Fixed::toInt( void ) const
{
    return getRawBits() >> this->_val;
}

std::ostream & operator<<(std::ostream & o, Fixed const & val )
{
    o << val.toFloat();
    return o;
}

std::istringstream &   operator>>( std::istringstream & o, Fixed & val )
{
    std::string tmp;
    int     i;
    float   fr = 0, mlt = 0.1, v = 0;

    o >> tmp;
    i = 0;
    while(std::isdigit(tmp[i]))
    {
        v = v * 10 + (tmp[i++] - 48);
    }
    if (tmp[i] && !std::isdigit(tmp[i]) && tmp[i] != '.')
    {
        std::cerr << "Parse error" << std::endl;
        exit(1);
    }
    if (tmp[i] && tmp[i] == '.')
    {
        i++;
        while(std::isdigit(tmp[i]))
        {
            fr += (tmp[i++] - 48) * mlt;
            mlt *= 0.1;
        }
    }
    if (tmp[i] && !std::isdigit(tmp[i]))
    {
        std::cerr << "Parse error" << std::endl;
        exit(1);
    }
    val = Fixed(v + fr);
    return  o;
}

Fixed Fixed::operator+( Fixed const & rhs )
{
    return Fixed(rhs.toFloat() + this->toFloat());
}

Fixed Fixed::operator-( Fixed const & rhs )
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*( Fixed const & rhs )
{
    return Fixed(rhs.toFloat() * this->toFloat());
}

Fixed Fixed::operator/( Fixed const & rhs )
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++( void )
{
    ++this->_point;
    return *this;
}

Fixed & Fixed::operator--( void )
{
    --this->_point;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed   tmp = *this;
    this->_point++;
    return tmp;
}

Fixed Fixed::operator--( int )
{
    Fixed   tmp = *this;
    this->_point--;
    return tmp;
}

bool    Fixed::operator>=( Fixed const & rhs ) const
{
    return this->toFloat() >= rhs.toFloat();
}

bool    Fixed::operator<=( Fixed const & rhs ) const
{
    return this->toFloat() <= rhs.toFloat();
}

bool    Fixed::operator>( Fixed const & rhs ) const
{
    return this->toFloat() > rhs.toFloat();
}

bool    Fixed::operator<( Fixed const & rhs ) const
{
    return this->toFloat() < rhs.toFloat();
}

bool    Fixed::operator==( Fixed const & rhs ) const
{
    return this->toFloat() == rhs.toFloat();
}

bool    Fixed::operator!=( Fixed const & rhs ) const
{
    return this->toFloat() != rhs.toFloat();
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    return a.getRawBits() > b.getRawBits() ? b : a;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
    return a.toFloat() > b.toFloat() ? b : a;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    return a.getRawBits() < b.getRawBits() ? b : a;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
    return a.toFloat() < b.toFloat() ? b : a;
}