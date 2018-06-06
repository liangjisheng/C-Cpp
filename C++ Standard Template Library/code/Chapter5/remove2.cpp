#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    list<int> coll;

    for(int i=1;i<=6;i++){
        coll.push_front(i);
        coll.push_back(i);
    }

    // print
    cout << "pre: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    // remove all elements with value 3
    // retain new end ,remove 返回一个新的终点
    list<int>::iterator newend = remove(coll.begin(),coll.end(),3);

    // print resulting elements of the collection
    cout << "post: ";
    copy(coll.begin(),newend,
         ostream_iterator<int>(cout," "));
    cout << endl;

    // print number of resulting elements
    cout << "number of removed elements: "
        << distance(newend,coll.end()) << endl;

    // remove "removed" elements,删除参数所指示区间的所有元素
    coll.erase(newend,coll.end());

    // print all elements of the modified collection
    cout << "erase post: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    return 0;
}
