#include <iostream>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::make_pair;
using std::string;
using std::unordered_map;

template<class T>
void printMap(const T& m)
{
    for(auto& p : m){
        cout << p.first << " (phone: " << p.second << ")" << endl;
    }
    cout << "----------" << endl;
}

int main()
{
    // Create a hash table.
    unordered_map<string,string> um = {
        {"Mary","123"},
        {"John","456"}
    };

    // 函数模板可以自动推到模板参数类型
    printMap(um);

    // Add/remove some phone numbers.
    um.insert(make_pair("John.D","321"));
    um["Johan"] = "789";
    um["Frank"] = "400";
    um.erase("Frank");

    printMap(um);

    // Find the bucket index for a specific key.
    int bucket = um.bucket("Mary");
    cout << "Mary is in bucket " << bucket
        << " which contains the following "
        << um.bucket_size(bucket) << " elements: " << endl;
    // Get begin and end iterators for the elements in this bucket.
    // 'auto' is being used here. The complier will derive the type
    // of both iterators as unordered_map<string,string>::const_local_iterator
    auto liter = um.cbegin(bucket);
    auto literEnd = um.cend(bucket);
    while(liter != literEnd) {
        cout << "\t" << liter->first << " (phone: "
            << liter->second << ")" << endl;
        ++liter;
    }
    cout << "----------" << endl;

    // print some statistics abouts the hash table
    cout << "There are " << um.bucket_count() << " buckets" << endl;
    cout << "Average number of elements in a bucket is "
        << um.load_factor() << endl;

    return 0;
}
