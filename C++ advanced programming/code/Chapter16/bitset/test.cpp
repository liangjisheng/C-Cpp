#include <iostream>
#include "CableCompany.h"
using namespace std;

int main()
{
    CableCompany mycc;
    auto basic_pkg = "1111000000";
    auto premium_pkg = "1111111111";
    auto sports_pkg = "0000100000";
    mycc.addPackage("basic",bitset<kNumChannels>(basic_pkg));
    mycc.addPackage("premium",bitset<kNumChannels>(premium_pkg));
    mycc.addPackage("sports",bitset<kNumChannels>(sports_pkg));
    mycc.newCustomer("Mary","basic");
    mycc.addPackageToCustomer("Mary","sports");

    cout << mycc.getCustomerChannels("Mary") << endl;

    return 0;
}
