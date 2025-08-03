#include <cstring>
class MyString  {
    private:
    char * str;
    MyString(); // No args constructor
    MyString(const char * s); // overloaded constructor
    MyString(const MyString &source); // copy constructor
    MyString(MyString &&source);
    ~MyString(); // destructor

    
};
MyString::MyString():str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char * s):str(nullptr) {
    if(s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

MyString::MyString(const MyString &soruce):str(nullptr) {
    if(soruce.str == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        str = new char [strlen(soruce.str) + 1];
        strcpy(str, soruce.str);
    }
}

MyString::MyString(MyString &&soruce):str(soruce.str) {
    soruce.str = nullptr;
}

MyString::~MyString() {
    delete []str;
}

