
// ʹ�÷º���������д��������ĺ���������������Լ���״̬��
// ���Ա���ȷ�ĳ�ʼ��

#include <iostream>
#include <list>
#include <algorithm>
#include "print.hpp"
using namespace std;

// function object that adds the value with which it is initialized
class AddValue{
private:
    int theValue;   // the value to add
public:
    AddValue(int v) : theValue(v) {}
    // the function call for the element adds the value
    void operator() (int& elem) const{
        elem += theValue;
    }
};

int main()
{
    list<int> coll;

    for(int i=1;i<=9;++i){
        coll.push_back(i);
    }

    PRINT_ELEMENTS(coll,"initialized: ");

    // add value 10 to each element
    for_each(coll.begin(),coll.end(),   // range
             AddValue(10));             // operation

    PRINT_ELEMENTS(coll,"after adding 10: ");

    // add value of first element to each element
    for_each(coll.begin(),coll.end(),
             AddValue(*coll.begin()));

    PRINT_ELEMENTS(coll,"after adding first element: ");

    return 0;
}