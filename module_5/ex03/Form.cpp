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
// 04.03.2021⠀⠀⠀⠀
//
#include "Form.hpp"
#include "iostream"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Form::Form( void ) : _name("def"), _req_sign(0), _req_exec(0) {
}

Form::Form( std::string name, int sign, int exec ) :
    _name(name), _sign(0), _req_sign(sign), _req_exec(exec) {
    if ( this->_req_sign < 1)
        Form::GradeTooHighException(this->_req_sign, this->_name);
    else if ( this->_req_sign > 150)
        Form::GradeTooLowException(this->_req_sign, this->_name);
    else if ( this->_req_exec < 1)
        Form::GradeTooHighException(this->_req_exec, this->_name);
    else if ( this->_req_exec > 150)
        Form::GradeTooLowException(this->_req_exec, this->_name);
}

Form::~Form( void ) {
}

Form::Form( Form const &src ) :
    _name(src.getName()), _sign(src.getSign()),  _req_sign(src.getReqSign()),
    _req_exec(src.getReqExec()) {
}

Form &Form::operator=( Form const &rhs ) {
    this->_sign = rhs.getSign();
    return *this;
}

void    Form::GradeTooHighException(int const g, std::string const n) const {
    if (g == 0)
        std::cout << g << " grade exception(high) for " << n << std::endl;
    else
        std::cout << n << " grade can't be negative" << std::endl;
    throw std::exception();
}

void    Form::GradeTooLowException(int const g, std::string const n) const {
    std::cout << g << " grade exception(low) for " << n << std::endl;
    throw std::exception();
}

std::string const   Form::getName() const
{
    return this->_name;
}

bool    Form::getSign() const
{
    return this->_sign;
}

int    Form::beSigned(Bureaucrat const * bur)
{
    if (bur->getGrade() <= this->getReqSign())
        this->_sign = 1;
    else
    {
        std::cout << "Bureaucrat " << bur->getName() << " grade ";
        std::cout << bur->getGrade() << " lower then ";
        this->GradeTooLowException( this->_req_sign, this->_name);
    }
    return (1);
}

int     Form::getReqSign() const
{
    return this->_req_sign;
}

int     Form::getReqExec() const
{
    return this->_req_exec;
}

std::ostream & operator<<(std::ostream & o, Form const & f)
{
    o << "Form " << f.getName() << ", req grade for sign ";
    o << f.getReqSign() << ", req grade for execute ";
    o << f.getReqExec() << " form is ";
    if (f.getSign())
        o << "signed";
    else
        o << "unsigned";
    o << std::endl;
    return o;
}

void    Form::setTarget(std::string target)
{
    this->_target = target;
}

std::string const   Form::getTarget() const
{
    return this->_target;
}

Form::Exec::Exec(Bureaucrat const &bur, Form const &form)
{
    if (!form.getSign())
    {
        std::cout << "form is unsigned" << std::endl;
        throw std::exception();
    }
    else if (bur.getGrade() > form.getReqExec())
    {
        std::cout << bur.getGrade() << " GradeTooLow for ";
        std::cout << bur.getName() << std::endl;
        throw std::exception();
//        bur.GradeTooLowException(bur.getGrade(),bur.getName());
    }
}