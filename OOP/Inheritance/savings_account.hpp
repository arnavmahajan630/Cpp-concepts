#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "account.hpp"

class Savings_Account : public Account {
    Savings_Account();
    ~Savings_Account();
    void deposit(double d);
    void withdraw(double d);

};
#endif