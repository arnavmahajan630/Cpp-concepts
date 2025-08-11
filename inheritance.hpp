#include <iostream>
class Account {
    public:
    Account();
    ~Account();
    void deposit(double amount);
    void withdraw(double amount);
};

void Account::deposit(double amount) {
    std::cout << "Deposit method called with amount " << amount << "\n";
}

void Account::withdraw(double amount) {
    std::cout << "Withdraw method called with amount " << amount << "\n";
}

class Savings: public Account {
    public:
    Savings();
    ~Savings(); 
    void deposit(double amount);
    void withdraw(double amount);
    
};

void Savings::deposit(double amount) {
    std::cout << "Deposit method called with amount " << amount << "\n";
}

void Savings::withdraw(double amount) {
    std::cout << "Withdraw method called with amount " << amount << "\n";
}