#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    list<int> coll1;
    list<int>::iterator ListIntPos;
    vector<int> coll2;
    vector<int>::iterator VectorIntPos;

    for(int i=1;i<=9;i++)
        coll1.push_back(i);

    for(ListIntPos=coll1.begin();ListIntPos!=coll1.end();++ListIntPos)
        cout<<*ListIntPos<<' ';
    cout<<endl;

    // resize destination to have enough room for the overwriting algorithm
    coll2.resize(coll1.size());

    copy(coll1.begin(),coll1.end(),     // source
         coll2.begin());                // destination

    for(VectorIntPos=coll2.begin();VectorIntPos!=coll2.end();++VectorIntPos)
        cout<<*VectorIntPos<<' ';
    cout<<endl;

    deque<int> coll3(coll1.size());
    deque<int>::iterator DequeIntPos;
    copy(coll1.begin(),coll1.end(),coll3.begin());

    for(DequeIntPos=coll3.begin();DequeIntPos!=coll3.end();++DequeIntPos)
        cout<<*DequeIntPos<<' ';
    cout<<endl;

    return 0;
}
