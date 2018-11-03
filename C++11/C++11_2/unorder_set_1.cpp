#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;


int main()
{
    unordered_set<int> unorder_set;
    unorder_set.insert(7);
    unorder_set.insert(5);
    unorder_set.insert(3);
    unorder_set.insert(4);
    unorder_set.insert(6);
    cout << "unorder_set: " << endl;
    for (auto itor : unorder_set)
        cout << itor << " ";
    cout << endl;

    set<int> set;
    set.insert(7);
    set.insert(5);
    set.insert(3);
    set.insert(4);
    set.insert(6);
    cout << "set: " << endl;
    for (auto itor : set)
        cout << itor << ' ';
    cout << endl;

    return 0;
}
