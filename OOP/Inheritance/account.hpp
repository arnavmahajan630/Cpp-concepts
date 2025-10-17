#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
class Account {
    private:
    int bal;
    public:
    Account();
    Account(int bal);
    ~Account();
    int balance() {return bal;}
};
#endif