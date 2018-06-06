#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    list<int> coll1;
    for(int i=1;i<=9;i++) {
        coll1.push_back(i);
    }

    // print
    cout << "list<int> coll1 :";
    for(auto iter = coll1.begin();iter!=coll1.end();++iter)
        cout << *iter << ' ';
    cout << endl;


    vector<int> coll2;
    copy(coll1.begin(),coll1.end(),back_inserter(coll2));
    // back_inserter内部调用push_back()，在尾端插入元素
    // vector,deque,list提供push_back();

    // print
    cout << "vector<int> coll2 :";
    for(auto iter = coll2.begin();iter!=coll2.end();++iter)
        cout << *iter << ' ';
    cout << endl;


    deque<int> coll3;
    copy(coll1.begin(),coll1.end(),front_inserter(coll3));
    // front_inserter内部调用push_front(); deque,list提供push_front();

    // print
    cout << "deque<int> coll3 :";
    for(auto iter = coll3.begin();iter!=coll3.end();++iter)
        cout << *iter << ' ';
    cout << endl;

    // -only inserter that works for associative collections
    set<int> coll4;
    copy(coll1.begin(),coll1.end(),
         inserter(coll4,coll4.begin()));
    // inserter内部调用insert(),并以新值和新位置作为参数
    // 所有STL容器都提供有insert()成员函数

    // print
    cout << "set<int> coll4 :";
    for(auto iter=coll4.begin();iter!=coll4.end();++iter)
        cout << *iter << ' ';
    cout << endl;

    return 0;
}
