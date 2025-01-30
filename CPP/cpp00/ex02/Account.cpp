#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account(void)
{
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
                                        _amount(initial_deposit),
                                        _nbDeposits(0),
                                        _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
    return;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(nullptr);
    struct tm *ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", ltm);
    std::cout << buffer;
    return;
}

void Account::makeDeposit(int deposit)
{
    if (deposit > 0)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        _totalAmount += deposit;
        _amount += deposit;
        std::cout << "deposit:" << deposit << ";";
        std::cout << "amount:" << _amount << ";";
        _totalNbDeposits++;
        _nbDeposits++;
        std::cout << "nb_deposits:" << _nbDeposits << std::endl;
    }
    return;
}

bool Account::makeWithdrawal(int withdrawl)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";

    if (withdrawl > _amount || withdrawl == 0)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    else
    {
        std::cout << "withdrawal:" << withdrawl << ";";
        _amount -= withdrawl;
        _totalAmount -= withdrawl;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        std::cout << "amount:" << _amount << ";";
        std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
    return;
}
