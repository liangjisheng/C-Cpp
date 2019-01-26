#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    // Crate a vector of strings ,using uniform initialization
    vector<string> myVector = {"A first string","A second string"};
    // Add some strings to the vector using push_back
    myVector.push_back("A third string");
    myVector.push_back("The last string in the vector");
    // print the elements using a range-based for loop
    for(const auto& str : myVector)
        cout<< str <<endl;

    cout<<endl;
    // Iterator over the elements in the vector and print them once more
    // c开头的是C++11的标准，
    for(auto iter = myVector.cbegin();
        iter != myVector.cend();++iter){
            cout<< *iter <<endl;
        }

    return 0;
}
