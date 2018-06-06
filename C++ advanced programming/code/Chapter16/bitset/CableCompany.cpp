
#include <iostream>
#include "CableCompany.h"
#include <stdexcept>

using std::string;
using std::bitset;
using std::out_of_range;
using std::invalid_argument;

void CableCompany::addPackage(const string& packageName,
                              const bitset<kNumChannels>& channels)
{
    // uniform initialize_list
    mPackages.insert({packageName, channels});
}

void CableCompany::removePackage(const string& packageName)
{
    mPackages.erase(packageName);
}

void CableCompany::newCustomer(const string& name,const string& package)
{
    // Get a reference to the specified package.
    auto it = mPackages.find(package);
    if(it == mPackages.end()){
        throw out_of_range("Invalid package");
    }

    // Create the account with the bitset representing that package.
    // Note that 'it' refers to a name/bitset pair.The bitset is the
    // second filed
    auto result = mCustomers.insert({name,it->second});
    if(!result.second){
        // Customer was already in the database.Nothing changed.
        throw invalid_argument("Duplicate customer");
    }
}

void CableCompany::newCustomer(const string& name,
                               const bitset<kNumChannels>& channels)
{
    auto result = mCustomers.insert({name,channels});
    if(!result.second) {
        // Customer was already in the database.Nothing changed.
        throw invalid_argument("Duplicate customer");
    }
}

void CableCompany::addChannel(const string& name,int channel)
{
    auto it = mCustomers.find(name);
    if(it != mCustomers.end()){
        // We found this customer ;set the channel.
        // Note that 'it' is a reference to name/bitset pair.
        // The bitset is the second field.
        it->second.set(channel);
    }
    else
        throw invalid_argument("Unknown customer.");
}

void CableCompany::removeChannel(const string& name,int channel)
{
    auto it = mCustomers.find(name);
    if(it != mCustomers.end()){
        it->second.reset(channel);
    }
    else
        throw invalid_argument("Unknown customer.");
}

void CableCompany::addPackageToCustomer(const string& name,
                                        const string& package)
{
    // Find the package
    auto itPack = mPackages.find(package);
    if(itPack == mPackages.end()) {
        // That package doesn't exist. Throw an exception
        throw out_of_range("Invalid package");
    }

    // Find the customer.
    auto itCust = mCustomers.find(name);
    if(itCust != mCustomers.end()){
        itCust->second |= itPack->second;
    }
    else
        throw invalid_argument("Unknown customer");
}

void CableCompany::deleteCustomer(const string& name)
{
    mCustomers.erase(name);
}

bitset<kNumChannels>& CableCompany::getCustomerChannels(const string& name)
{
    auto it = mCustomers.find(name);
    if(it != mCustomers.end())
        return it->second;
    throw invalid_argument("Unknown customer");
}


