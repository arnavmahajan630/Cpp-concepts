#ifndef INRUNNER_HPP
#define INRUNNER_HPP

#include <iostream>
#include "account.hpp"
#include "savings_account.hpp"
using namespace std;
inline void inhertitance() {
    Account a = Account();
    cout << a.name << " whyyy " << a.balance << endl;
    Savings_Account b = Savings_Account();
    cout << b.name << endl;
    cout << b.int_rate << endl;
}
#endif