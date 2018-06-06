#ifndef BANKDB_H_INCLUDED
#define BANKDB_H_INCLUDED

#include "BankAccount.hpp"
#include <map>
#include <utility>
#include <stdexcept>

class BankDB
{
public:
    bool addAccount(const BankAccount& acct);
    void deleteAccount(int acctNum);
    BankAccount& findAccount(int acctNum);
    BankAccount& findAccount(const std::string& name);
    // Add all the accounts from db to this database.
    // Deletes all the accounts from db
    void mergeDatabase(BankDB& db);
    void print();
private:
    std::map<int,BankAccount> mAccounts;
};


bool BankDB::addAccount(const BankAccount& acct)
{
    // Do the actual insert,using the account number as the key
    auto res = mAccounts.insert(std::make_pair(acct.getAcctNum(),acct));
    // Return the bool field of the pair specifying success or failure
    return res.second;
}

void BankDB::deleteAccount(int acctNum)
{
    mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int acctNum)
{
    auto it = mAccounts.find(acctNum);
    if(mAccounts.end() == it){
        throw std::out_of_range("No account with that number.");
    }
    // Remember that iterators into maps refer to pairs of key/value
    return it->second;
}

BankAccount& BankDB::findAccount(const std::string& name)
{
    // Finding an element by a non-key attribute requires a linear
    // search through the elements
    for(auto& p : mAccounts){
        if(p.second.getClientName() == name)
            return p.second;
    }
    throw std::out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB& db)
{
    mAccounts.insert(db.mAccounts.begin(),db.mAccounts.end());
    db.mAccounts.clear();
}

void BankDB::print()
{
    for(auto& i : mAccounts){
        std::cout << i.first << " " << i.second.getClientName() << std::endl;
    }
    std::cout << std::endl;
}


#endif // BANKDB_H_INCLUDED
