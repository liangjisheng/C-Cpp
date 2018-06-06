#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void removeEmptyStrings(vector<string>& strings)
{
    auto it = remove_if(strings.begin(), strings.end(),
                        [](const string& str){ return str.empty();});
    // Erase the removed elements
    strings.erase(it,strings.end());
}

int main()
{
    vector<string> myVec = {"", "one", "", "two", "three", "four" };
    for(auto& str : myVec)
        cout << "\"" << str << "\"" << ' ';
    cout << endl;

    removeEmptyStrings(myVec);

    for(auto& str : myVec)
        cout << "\"" << str << "\"" << ' ';
    cout << endl;

    return 0;
}
