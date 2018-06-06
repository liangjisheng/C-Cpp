
// Binary predicates �ĵ�����;���ǱȽ�����������ض����ԡ�
// ���磬Ϊ���������Լ���ԭ���Ԫ�������������һ���򵥵�
// predicate ��ʽ�ṩ����Ԫ�棬���Ԫ�ر���֧��operator<
// ��������ʹ�ò�ͬ������ԭ����������ó���

// ����������ӣ�����ÿ���˵���������һ��Ԫ�ؽ�������

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

class Person{
public:
    string firstname() const;
    string lastname() const;
};

// binary function predicate
// - return whether a person is less than another person
bool personSortCirterion(const Person& p1,const Person& p2)
{
    return p1.lastname() < p2.lastname() ||
            (!(p1.lastname() < p2.lastname()) &&
             p1.firstname() < p2.firstname());
}

int main()
{
    deque<Preson> coll;
    ...
    sort(coll.begin(),coll.end(),   // range
         personSortCirterion);      // sort criterion
    ...

    return 0;
}
