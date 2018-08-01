#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> coll;
    vector<int>::iterator pos;

    coll.push_back(2);
    coll.push_back(5);
    coll.push_back(4);
    coll.push_back(1);
    coll.push_back(6);
    coll.push_back(3);

     // print
     cout<<"before sort:";
    for(pos=coll.begin();pos!=coll.end();++pos)
        cout<<*pos<<' ';
    cout<<endl;

    // find and print minimum and maximum elements
    pos = min_element(coll.begin(),coll.end());
    cout<<"min: "<<*pos<<endl;
    pos = max_element(coll.begin(),coll.end());
    cout<<"max: "<<*pos<<endl;

    // sort all elements
    sort(coll.begin(),coll.end());

     // print
     cout<<"after sort:";
    for(pos=coll.begin();pos!=coll.end();++pos)
        cout<<*pos<<' ';
    cout<<endl;

    // find the first element with value 3
    pos = find(coll.begin(),coll.end(),3);
    // reverse the order of the found element with value 3 and all following elements
    reverse(pos,coll.end());

    // print
    cout<<"after reverse 3 and coll.end(): ";
    for(pos=coll.begin();pos!=coll.end();++pos)
        cout<<*pos<<' ';
    cout<<endl;

    return 0;
}
