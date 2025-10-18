#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>
using namespace std;
class Account {
    public:
    double balance;
    std::string name;
    Account();
    ~Account();
    void deposit(double d);
    void withdraw(double d);
};

class Base {
    public:
    Base(){cout << "Base constructor called" << endl;}
    ~Base() {cout << "Base destructor called" << endl;}
    int a {0};  
    void display(){cout << "a: " << a << " b: " << b << " c: " << c <<endl;}
    protected:
    int b {0};
    private:
    int c {0};
};
#endif