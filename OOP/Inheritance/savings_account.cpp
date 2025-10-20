#include "savings_account.hpp"
#include <iostream>
Savings_Account::Savings_Account():int_rate(3) {}
Savings_Account::~Savings_Account() {}
void Savings_Account::withdraw(double d){
    std::cout << "withdrew from savings" << std::endl;
}

void Savings_Account::deposit(double d){
    std::cout << "Savings account got deposited" << std::endl;
}