#include <cstring>
#include <iostream>
class MyString  {
    private:
    char * str;
    public:
    // Constructors
    MyString(); // No args constructor
    MyString(const char * s); // overloaded constructor
    MyString(const MyString &source); // copy constructor
    MyString(MyString &&source)noexcept;
    // Operator Overloadings
    MyString& operator=(const MyString & rhs); // assignment overload (Copy)
    MyString& operator=(MyString &&rhs)noexcept; // assignment overload (move)  
    //friend MyString operator+(const MyString& lhs, const MyString& rhs); // not a member overload +
    //friend bool operator==(const MyString &lhs, const MyString &rhs);
    ~MyString(); // destructor
    
    // Getters
    const char * get_str() const {return str;} 
};
MyString::MyString():str(nullptr) {
    std::cout << "no args called\n";
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char * s):str(nullptr) {
    std::cout << "overloaded constructor called\n";
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
    std::cout << "copy constructor called\n";
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
    std::cout << "move constructor was called\n";
    soruce.str = nullptr;
}

MyString &MyString::operator=(const MyString & rhs) {
    std::cout << "copy overload was called\n";
    if(this == &rhs)return * this;
    else {
        delete []str;
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
    }
    return *this;
}
MyString &MyString::operator=(MyString &&rhs)noexcept {
    std::cout << "Move overload was called\n";
    if(this == &rhs)return *this;
    else {
        delete []str;
        str = rhs.str;
        rhs.str = nullptr;
    }
    return *this;
}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    std::cout << "adder overload was called\n";
    size_t len = strlen(lhs.get_str()) + strlen(rhs.get_str()) + 1;
    char * buffer = new char[len];
    strcpy(buffer, lhs.get_str());
    strcat(buffer, rhs.get_str());
    return MyString(buffer);
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.get_str(), rhs.get_str()) == 0;
}
bool operator!=(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.get_str(), rhs.get_str()) == 0;
}


MyString::~MyString() {
    delete []str;
}