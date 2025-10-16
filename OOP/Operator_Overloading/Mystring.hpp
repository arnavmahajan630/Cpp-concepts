#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <cstring>
#include <iostream>
using namespace std;
class MyString
{
private:
    char *str;
public:
    // Constructors
    MyString(); // No args default constructor
    MyString(const char * s); // paratermarized overloaded constructor
    MyString(const MyString &source); // copy constructor
    MyString(MyString &&source)noexcept; // move constructor

    // Assignment overloads
    MyString&operator=(const MyString&rhs); // copy overload
    MyString &operator=(MyString &&rhs)noexcept; // move overload

    // Increment overloads
    MyString operator++(int); // post (int)
    MyString operator++(); // pre increment

     // copy (add and assign += ) overloads
    MyString &operator+=(const MyString &rhs); // lval object
    MyString &operator+=(MyString &&rhs)noexcept;// rval object
    MyString &operator+=(const char * s); // free string

    ~MyString();// destructor

    // Non member functions Since they don't modify object they dont belong in class
    // operator + - * / == !=

    // Accessor
    const char * getstr() const {
        return str;
    }

    // friends // Stream Overloading for I/O
    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend ostream& operator<<(ostream& os, const MyString& obj);
    friend istream& operator>>(istream& is, MyString& obj);
};

// + overload
MyString operator+(const MyString &lhs, const MyString &rhs);

// Equality
bool operator==(const MyString &lhs, const MyString &rhs);
bool operator!=(const MyString &lhs, const MyString &rhs);

#endif