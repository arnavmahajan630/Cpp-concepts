#include <cstring>
#include <iostream>
using namespace std;
class MyString
{
private:
    char *str;
public:
    // Member Prototypes
    MyString(); // No args default constructor
    MyString(const char * s); // paratermarized overloaded constructor
    MyString(const MyString &source); // copy constructor
    MyString(MyString &&source)noexcept; // move constructor
    // Member Operator overloads
    MyString&operator=(const MyString&rhs); // assignment copy overload
    MyString &operator=(MyString &&rhs)noexcept;
    MyString operator++(int); // int means post increment
    ~MyString();// destructor

    // Non member functions Since they don't modify object they dont belong in class
    // operator + - * / == != stream insertions etc

    // Stream Overloading for cooler input and output
    // ostream & istream

    // member methods
    const char * getstr() const {
        return str;
    }

    // friends
    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
};
    //default
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

ostream &operator<<(ostream &os, const MyString &obj) {
    os << obj.getstr();
    return os;
}
istream &operator>>(istream &is, MyString &obj) {
    char * buff = new char[10000];
    is >> buff;
    obj = MyString(buff);
    delete []buff;
    return is;
}

MyString::~MyString() {
    delete []str;
}




