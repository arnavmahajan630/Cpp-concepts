#include <iostream>
#include "overloading.hpp"
using namespace std;
void  operatorOverloading() {
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
    cout << a.get_str() << endl; // prints hellonewworld

    // Post Increment
    MyString s("hello");
    s++;
    cout << s.get_str() << endl;
}

void Inheritance() {

}

int main() {
    //operatorOverloading();
    Inheritance();
    
    return 0;
}