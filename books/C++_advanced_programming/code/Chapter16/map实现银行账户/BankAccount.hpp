#ifndef BANKACCOUNT_HPP_INCLUDED
#define BANKACCOUNT_HPP_INCLUDED

#include <string>

class BankAccount
{
public:
    BankAccount(int acctNum,const std::string& name)
        : mAcctNum(acctNum),mClientName(name) {}
    void setAcctNum(int acctNum) { mAcctNum = acctNum; }
    int getAcctNum() const { return mAcctNum; }
    void setClientName(const std::string& name) { mClientName = name; }
    const std::string& getClientName() const { return mClientName; }
private:
    int mAcctNum;
    std::string mClientName;
};

#endif // BANKACCOUNT_HPP_INCLUDED
