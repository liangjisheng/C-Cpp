#include <iostream>
#include "BankDb.h"
using namespace std;

//void print(const BankDB& src)
//{
//    for(const auto& i : src){
//        cout << i.first << i.second.getClientName() << endl;
//    }
//}

int main()
{
    BankDB db;
    db.addAccount(BankAccount(100,"dog"));
    db.addAccount(BankAccount(200,"cat"));
    db.addAccount(BankAccount(300,"scott"));
    db.addAccount(BankAccount(400,"tiger"));
    db.print();

    cout << endl;
    try{
        auto& acct = db.findAccount(100);
        cout << "Found account 100" << endl;
        acct.setClientName("pig");

        auto& acct2 = db.findAccount("cat");
        cout << "Found account of cat:" << endl;
        auto& acct3 = db.findAccount(1000);
    }catch(const out_of_range&){
        cout << "Unable to find account" << endl;
    }

    cout << endl;
    db.print();

    return 0;
}
