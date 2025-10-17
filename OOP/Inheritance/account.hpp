#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
class Account {
    public:
    double balance;
    std::string name;
    Account();
    ~Account();
    void deposit(double d);
    void withdraw(double d);
};
#endif