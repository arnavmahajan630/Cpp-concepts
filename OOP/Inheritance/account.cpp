#include "account.hpp"
#include <iostream>

Account::~Account() {}
Account::Account() {}
void Account::deposit(double d) {
    std::cout << "deposited $" << d << std::endl;
}
void Account::withdraw(double d) {
    std::cout << "Withdrawn $" << d << std::endl;
}
