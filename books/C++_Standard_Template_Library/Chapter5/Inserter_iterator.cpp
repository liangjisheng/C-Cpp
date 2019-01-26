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
    // back_inserter�ڲ�����push_back()����β�˲���Ԫ��
    // vector,deque,list�ṩpush_back();

    // print
    cout << "vector<int> coll2 :";
    for(auto iter = coll2.begin();iter!=coll2.end();++iter)
        cout << *iter << ' ';
    cout << endl;


    deque<int> coll3;
    copy(coll1.begin(),coll1.end(),front_inserter(coll3));
    // front_inserter�ڲ�����push_front(); deque,list�ṩpush_front();

    // print
    cout << "deque<int> coll3 :";
    for(auto iter = coll3.begin();iter!=coll3.end();++iter)
        cout << *iter << ' ';
    cout << endl;

    // -only inserter that works for associative collections
    set<int> coll4;
    copy(coll1.begin(),coll1.end(),
         inserter(coll4,coll4.begin()));
    // inserter�ڲ�����insert(),������ֵ����λ����Ϊ����
    // ����STL�������ṩ��insert()��Ա����

    // print
    cout << "set<int> coll4 :";
    for(auto iter=coll4.begin();iter!=coll4.end();++iter)
        cout << *iter << ' ';
    cout << endl;

    return 0;
}
