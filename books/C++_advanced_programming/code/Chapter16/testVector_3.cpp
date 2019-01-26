#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> stringVector(10,"hello");
    for(auto it = begin(stringVector); it != end(stringVector); ++it) {
        it->append(" there");
    }

    cout << endl;
    for(auto it = begin(stringVector); it != end(stringVector); ++it){
        cout << *it << endl;
    }
    cout << endl;

    for(auto& str : stringVector) {
        str.append(" there");
    }

    cout << endl;
    for(auto it = begin(stringVector); it != end(stringVector); ++it){
        cout << *it << endl;
    }
    cout << endl;

    return 0;
}
