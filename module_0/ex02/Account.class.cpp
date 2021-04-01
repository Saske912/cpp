//##################################################################
//                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣴⣖⣁⣀⣀⡄⠀⠀⠀
//                                       ⠀⠀⠀⠀⠀⠀⢀⣀⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣤⣄⣀⣀
//                                       ⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁
//                                      ⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀
//                                      ⠀⠀⠀⠀⠀⣼⣿⡟⠀⢠⡲⠖⠀⣿⣿⣿⣿⣿⣿⣿⣉⠁⠀⠀⠀
//  ╱╱╱╱╭━╮╭╮                               ⣼⣿⣿⡷⢤⠤⠤⣥⡤⣿⠿⣿⣿⣿⡿⣿⣿⣷⡀
//  ╱╱╱╱┃╭╯┃┃                           ⠀⣀⣠⣼⣿⣿⣿⣧⠑⠟⠀⠈⠙⠱⢦⣿⣿⣿⠁⣸⣿⣿⣇⠀
//  ╭━━┳╯╰┳┫┃╭━━╮                       ⠊⠉⠉⠉⠉⠩⠞⠁⠀⠀⠄⠀⠀⡴⣿⣿⣿⠗⣵⣿⠡⠉⠉⠁⠀
//  ┃╭╮┣╮╭╋┫┃┃┃━┫                              ⠀⢡⠀⠀⠀⢈⣾⣟⣵⣯⣼⣿⣬⣄⣀⠀⠀
//  ┃╰╯┃┃┃┃┃╰┫┃━┫                           ⠀⠀⣶⣶⣶⣾⣥⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀
//  ┃╭━╯╰╯╰┻━┻━━╯                           ⠀⢺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡄
//  ┃┃                                     ⢠⢤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⡄
//  ╰╯                                  ⠀⠠⣰⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠇⠀⠀⠀⠀⠀
//#################################################################

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int     Account::nbAccounts = 0;
int     Account::totalAmount = 0;
int     Account::totalNbDeposits = 0;
int     Account::totalNbWithdrawals = 0;

int     Account::nbAmountCall = 0;

void    Account::displayStatus( void ) const 
{
    displayTimestamp();
    std::cout << "index:" << this->accountIndex << ';';
    std::cout << "amount:" << this->amount << ';';
    std::cout << "deposits:" << this->nbDeposits << ';';
    std::cout << "withdrawals:" << this->nbWithdrawals << std::endl;

    return ;
}

void    Account::displayAccountsInfos( void )
{
    displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ';';
    std::cout << "total:" << getTotalAmount() <<  ';';
    std::cout << "deposits:" << getNbDeposits() << ';';
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;

    return ; 
}

int     Account::getNbAccounts( void )
{
    return nbAccounts;
} 

int     Account::getTotalAmount( void )
{
    return totalAmount;
}

int     Account::getNbDeposits( void )
{
    return totalNbDeposits;
}

int     Account::getNbWithdrawals( void )
{
    return totalNbWithdrawals;
}

Account::Account( int initial_deposit )
{
    this->totalAmount += initial_deposit;
    this->amount = initial_deposit;
    this->accountIndex =this->nbAccounts;
    this->nbAccounts += 1;
    this->nbDeposits = 0;
    this->nbWithdrawals = 0;
    displayTimestamp();
    std::cout << "index:" << this->accountIndex << ';';
    std::cout << "amount:" << checkAmount();
    std::cout << ";created" << std::endl;

    return ;
}

Account::~Account( void )
{
    displayTimestamp();
    std::cout << "index:" << this->accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";closed" << std::endl;

    return ;
}    

Account::Account( void )
{
    return ;
}

void    Account::makeDeposit( int deposit )
{
    displayTimestamp();
    std::cout << "index:"<< this->accountIndex << ";p_amount:" << this->amount;
    std::cout << ";deposit:" << deposit << ";amount:";
    this->amount += deposit;
    this->nbDeposits += 1;
    this->totalNbDeposits += 1;
    this->totalAmount += deposit;
    std::cout << checkAmount() << ";nb_deposits:" << this->nbDeposits << std::endl;

    return ;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    displayTimestamp();
    std::cout << "index:" << this->accountIndex << ";p_amount:";
    std::cout << checkAmount() << ";withdrawal:";
    if (withdrawal > checkAmount())
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    else
    {
        std::cout << withdrawal;
        this->amount -= withdrawal;
        this->totalAmount -= withdrawal;
        this->totalNbWithdrawals += 1;
        this->nbWithdrawals += 1;
        std::cout << ";amount:" << checkAmount() << ";nb_withdrawals:";
        std::cout << this->nbWithdrawals << std::endl;
    }

    return true;
}

int     Account::checkAmount( void ) const
{
    const_cast< Account * >( this )->nbAmountCall++;
    return this->amount;
}

void    Account::displayTimestamp( void )
{
    time_t      tim;
    char buffer [80];
    struct tm * timeinfo;

    time(&tim);
    timeinfo = localtime(&tim);
    strftime (buffer,80,"%Y%m%d_%H%M%S",timeinfo);
    std::cout << "[" << buffer << "] ";
}