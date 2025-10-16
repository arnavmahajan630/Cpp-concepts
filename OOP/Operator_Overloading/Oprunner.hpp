#ifndef OPRUNNER_HPP
#define OPRUNNER_HPP

#include <iostream>
#include "Mystring.hpp"
using namespace std;
inline void  operatorOverloading() {
    // Calls Copy Constructor (DEEP COPY) Copies a to b
    MyString a = "Hello";
    MyString b = a;
    //cout << a.get_str() << endl;
    //cout << b.get_str() << endl; 

    // Force Call Move Constructor
    MyString c = "New";
    //cout << "c: "<< c.get_str() << endl;
    //cout << "b: " << b.get_str() << endl;
    
    // Assignment Operator Overload Copy & Move
    MyString d = "World";
    a = a + c + d;
    cout << a.getstr() << endl; // prints hellonewworld

    // Post Increment
    MyString s("hello");
    s++;
    cout << s.getstr() << endl;

    // printing to stream smoothly
    cout << s << endl; //hellohello gets printed again. verified

    // inputing to ostream
    MyString j = "";
    cin >> j;
    cout << j + MyString("21") << endl; // desipite being rval compiler binds
    // the issue is that this MyString is a temp value and can bind only 
    // to a const lvalue i had put non const rhl thus it could not bind 
    
    // c++ Compiler creator rocks

    // += overloads
    MyString k = "";
    cin >> k;
    k+=j;
    cout << k << endl;
    k+=MyString("abc");
    cout << k << endl;
    k+= "doakes";
    cout << k << endl;
}                                    

#endif