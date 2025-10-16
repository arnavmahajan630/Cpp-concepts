#include "Mystring.hpp"

MyString::MyString():str(nullptr) {
    cout << "default constructor called\n";
    str = new char[1];
    str[0] = '\0';
}

// param
MyString::MyString(const char * s):str(nullptr) {
    cout << "Overloaded constructor called\n";
    if(s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else  {
        str = new char[strlen(s) + 1];
        str = strcpy(str, s);
    }
}

// deep copy
MyString::MyString(const MyString &source):str(nullptr) {
    cout << "Copy Constructor called\n";
    if(source.str == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else  {
        str = new char[strlen(source.str) + 1];
        str = strcpy(str, source.str);
    }
}

// move
MyString::MyString(MyString &&source)noexcept:str(source.str) {
    source.str = nullptr;
}

// assginemnt copy =
MyString &MyString::operator=(const MyString & rhs) {
    cout << "assignemnt copy overload called \n";
    if(this == &rhs)return *this;
    delete []str;
    str = new char[(2*(strlen(rhs.str))) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// move copy overload
MyString &MyString::operator=(MyString &&rhs)noexcept {
    cout << "assignment move overload called\n";
    if(this == &rhs)return *this;
    delete []str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// + on 2 lvalues (an rval bind to const lvals !!!!)
MyString operator+(const MyString &lhs, const MyString&rhs) {
    cout << "addition overload lhs + lhs called\n";
    size_t len = strlen(rhs.getstr()) + strlen(lhs.getstr()) + 1; // since not a friend needs method to access
    char * buffer = new char[len];
    strcpy(buffer, lhs.getstr());
    strcat(buffer, rhs.getstr());
    return MyString(buffer);
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.getstr(), rhs.getstr()) == 0;
}
bool operator!=(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.getstr(), rhs.getstr()) == 0;
}

MyString MyString::operator++(int) {
    std::cout << "post increment was called\n";
    MyString temp(*this);
    size_t len = strlen(str);
    char * buff = new char[2*len + 1];
    strcpy(buff, str);
    strcat(buff, str);
    delete []str;
    str = buff;
    return temp;
}

// ostream overload
ostream &operator<<(ostream &os, const MyString &obj) {
    os << obj.getstr();
    return os;
}
// istream overload
istream &operator>>(istream &is, MyString &obj) {
    char * buff = new char[10000];
    is >> buff;
    obj = MyString(buff);
    delete []buff;
    return is;
}

// copy += overload
MyString& MyString::operator+=(const MyString &rhs) {
    cout << "copy += assignment called" << endl;
    size_t l1 = strlen(rhs.getstr());
    size_t l2 = strlen(str);
    char * buffer = new char[l1 + l2 + 1];
    strcpy(buffer, str);
    strcat(buffer, rhs.getstr());
    delete[]str;
    str = buffer;
    return *this; 
} 

// move += overload
MyString & MyString::operator+=(MyString && rhs)noexcept {
    cout << "move += assignment called" << endl;
    size_t l1 = strlen(rhs.getstr());
    size_t l2 = strlen(str);
    char* buffer = new char[l1 + l2 + 1];
    strcpy(buffer, str);
    strcat(buffer, rhs.str);
    delete [] str;
    str = buffer;
    rhs.str = nullptr;
    return *this;
}
// const char += overload
MyString & MyString::operator+=(const char * s) {
    cout << "const char += assignment called" << endl;
    if(!s)return *this;
    size_t len1 = strlen(str);
    size_t len2 = strlen(s);

    char* buffer = new char[len1 + len2 + 1];
    strcpy(buffer, str);
    strcat(buffer, s);

    delete [] str;
    str = buffer;
    return * this;
}
MyString::~MyString() {
    delete []str;
}