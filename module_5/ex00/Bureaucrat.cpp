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
// 02.03.2021⠀⠀⠀⠀
//
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat( void )
{}

Bureaucrat::Bureaucrat( std::string name, int grade ) :
    _name(name), _grade(grade)
{
    if ( this->_grade < 1)
        Bureaucrat::GradeTooHighException(this->_grade, this->_name);
    else if ( this->_grade > 150)
        Bureaucrat::GradeTooLowException(this->_grade, this->_name);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName())
{
    this->_grade = src.getGrade();
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const & rhs)
{
    this->_grade = rhs.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat( void ) {
}

void    Bureaucrat::GradeTooHighException(int g, std::string const n) {
    if (g == 0)
        std::cout << g << " GradeTooHigh for " << n << std::endl;
    else
        std::cout << n << " grade can't be negative" << std::endl;
    throw std::exception();
}

void    Bureaucrat::GradeTooLowException(int g, std::string const n) {
    std::cout << g << " GradeTooLow for " << n << std::endl;
    throw std::exception();
}

std::string const   Bureaucrat::getName() const
{
    return this->_name;
}

int        Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::decGrade()
{
    if ( this->_grade == 150)
        Bureaucrat::GradeTooLowException(++this->_grade, this->_name);
    else
        this->_grade++;
}

void    Bureaucrat::incGrade()
{
    if ( this->_grade == 1)
        Bureaucrat::GradeTooHighException(--this->_grade, this->_name);
    else
        this->_grade--;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bur)
{
    o << bur.getName() << ", bureaucrat grade ";
    o << bur.getGrade() << "." << std::endl;
    return o;
}