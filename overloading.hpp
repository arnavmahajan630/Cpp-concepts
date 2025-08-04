#include <cstring>
class MyString  {
    private:
    char * str;
    // Constructors
    MyString(); // No args constructor
    MyString(const char * s); // overloaded constructor
    MyString(const MyString &source); // copy constructor
    MyString(MyString &&source)noexcept;
    // Operator Overloadings
    MyString &MyString::operator=(const MyString & rhs); // assignment overload (Copy)
    MyString &MyString::operator=(MyString &&rhs)noexcept; // assignment overload (move)  
    ~MyString(); // destructor
    
    // Getters
    const char * get_str() const {return str;} 
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

MyString::MyString(MyString &&soruce)noexcept:str(soruce.str) {
    soruce.str = nullptr;
}

MyString &MyString::operator=(const MyString & rhs) {
    if(this == &rhs)return * this;
    else {
        delete []str;
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
    }
    return *this;
}
MyString &MyString::operator=(MyString &&rhs)noexcept {
    if(this == &rhs)return *this;
    else {
        delete []str;
        str = rhs.str;
        rhs.str = nullptr;
    }
}



MyString::~MyString() {
    delete []str;
}