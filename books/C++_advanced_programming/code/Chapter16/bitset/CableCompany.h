#ifndef CABLECOMPANY_H_INCLUDED
#define CABLECOMPANY_H_INCLUDED

#include <string>
#include <map>
#include <bitset>

const size_t kNumChannels = 10;     // 表示共有10个频道

class CableCompany
{
public:
    // Add the package with the specified channels to the database
    void addPackage(const std::string& packageName,
                    const std::bitset<kNumChannels>& channels);
    // Removes the specified package from the database
    void removePackage(const std::string& packageName);
    // Adds customer to database with initial channels found in package.
    // Throws out_of_range if the package name is invalid.
    // Throws invalid_argument if the customer is already known.
    void newCustomer(const std::string& name,
                     const std::string& package);
    // Adds customer to database with given initial channels.
    // Throws invalid_argument if the customer is already known.
    void newCustomer(const std::string& name,
                     const std::bitset<kNumChannels>& channels);
    // Adds the channel to the customers profile.
    // Throws invalid_argument if the customer is unknown.
    void addChannel(const std::string& name,int channel);
    // remove
    void removeChannel(const std::string& name,int channel);
    // Adds the specified package to the customers profile.
    // Throws out_of_range if the package name is invalid.
    // Throws invalid_argument if the customer is unknown.
    void addPackageToCustomer(const std::string& name,
                              const std::string& package);
    // remove
    void deleteCustomer(const std::string& name);
    // Retrieves the channels to which a customer subscribes.
    // Throws invalid_argument if the customer is unknown.
    std::bitset<kNumChannels>& getCustomerChannels(const std::string& name);
private:
    typedef std::map<std::string,std::bitset<kNumChannels> > MapType;
    MapType mPackages;      // 表示套餐频道
    MapType mCustomers;     // 表示自定义频道
};

#endif // CABLECOMPANY_H_INCLUDED
