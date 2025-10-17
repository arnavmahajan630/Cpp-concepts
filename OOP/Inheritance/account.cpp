#include "account.hpp"
#include <iostream>

Account::~Account() {}
Account::Account():balance(0.0),name("An account") {}
void Account::deposit(double d) {
    std::cout << "Account got deposited $" << d << std::endl;
}
void Account::withdraw(double d) {
    std::cout << "Account was Withdrawn by $" << d << std::endl;
}
