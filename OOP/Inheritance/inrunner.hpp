#ifndef INRUNNER_HPP
#define INRUNNER_HPP

#include <iostream>
#include "account.hpp"
#include "savings_account.hpp"
using namespace std;
inline void inhertitance() {
    Account a = Account();
    a.deposit(100);
    a.withdraw(20);
    Savings_Account b = Savings_Account();
    b.deposit(32);
    b.withdraw(12);
}
#endif