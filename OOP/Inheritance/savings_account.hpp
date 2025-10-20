#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "account.hpp"

class Savings_Account : public Account {
    public:
    int int_rate;
    Savings_Account();
    ~Savings_Account();
    void deposit(double d) override;
    void withdraw(double d);

};


class Derived : public Base {
    // Since Derived inherits Base as public
    /*a = public
      b = protected
      c = private ofc but it is inherited
    */
   int double_val;
   public:
  
   // simply shows when derived is called base is called
   Derived() : Base{}, double_val(0){cout << "derived from base constructor called" << endl;}
   Derived(int x) : Base{x}, double_val(x*2){cout << "dervied from base args constructor called " << endl;}
   ~Derived() {cout << "Derived destructor called" << endl;}
//    void modify(){a = 21; b = 32;} // a cannot be modified
//    void access_base(){a = 100; b = 200; } // b is modified 
    //   since it has been inherited and now belongs in D so it can modify itself. but c even though inherited cannot be modified since its inaccecible
    // We cannot also modify or even print a since it's private
    void display(){cout << "double_val: " <<  double_val << endl;}
};
#endif