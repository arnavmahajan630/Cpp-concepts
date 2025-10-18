#ifndef INRUNNER_HPP
#define INRUNNER_HPP

#include <iostream>
#include "account.hpp"
#include "savings_account.hpp"
using namespace std;
inline void inhertitance() {
    // Account a = Account();
    // cout << a.name << " whyyy " << a.balance << endl;
    // Savings_Account b = Savings_Account();
    // cout << b.name << endl;
    // cout << b.int_rate << endl;

    Base base;
    base.a = 100;
    base.display();
    Derived der;
    der.modify();
    der.display();
   // base.b = 100; inaccecible since b is private
   // base.c = 100; protected not possible

   /*From the constructor logs we can understand that base object is created first
    Then we have the Derived object creation. similarly the Derived 
    object is destroyed before the main object*/

    
}
#endif