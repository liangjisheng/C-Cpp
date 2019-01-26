#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    list<int> coll;

    for(int i=1;i<=6;++i){
        coll.push_front(i);
        coll.push_back(i);
    }

    // print
    cout << "pre: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    // remove all elements with value 3
    // - poor performance
    coll.erase(remove(coll.begin(),coll.end(),4),coll.end());

    cout << "after delete value 4 poor performance: ";
    cout << coll.size() << endl;
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    // remove all elements with value 4
    // - good performance
    coll.remove(4);

    cout << "after delete value 4 good performance: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    return 0;
}
