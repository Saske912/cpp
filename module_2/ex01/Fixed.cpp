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

Fixed::Fixed( void ) : _point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=( Fixed const &rhs )
{
    std::cout << "Assignation operator called" << std::endl;
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
    std::cout << "Int constructor called" << std::endl;
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
    std::cout << "Float constructor called" << std::endl;
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