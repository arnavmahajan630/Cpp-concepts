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
    virtual void deposit(double d);
    void withdraw(double d);
};

class Base {
    int value;
    public:
    Base():value(){cout << "Base constructor called" << endl;}
    Base(int x):value(x){cout << "Param constructor called" << endl;}
    ~Base() {cout << "Base destructor called" << endl;}
    int a {0};  
    void display(){cout << "val: " << value << endl;}
    // protected:
    // int b {0};
    // private:
    // int c {0};
};
#endif